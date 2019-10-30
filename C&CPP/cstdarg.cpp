// cpp中变长参数的使用
#include <cstdarg>
#include <iostream>
using namespace std;
void minprintf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;
    va_start(ap, fmt);
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            cout << *p;
            continue;
        }
        switch (*++p)
        {
        case 'd':
            ival = va_arg(ap, int);
            cout<<ival;
            break;
        case 'f':
            dval = va_arg(ap, double);
            cout<<dval;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
            {
                cout << *sval;
            }
            break;

        default:
        cout<<*p;
            break;
        }
        cout<<endl;
    }
    va_end(ap);
}
int main()
{
    minprintf("%d%d",2,3);
}
// 可变参头文件 <stdarg.h>
// 主要依赖五个宏: va_list,va_start, va_arg, va_end, va_copy
// 其中 va_copy 是 c99 新引进的

//     va_list
//         本质为char*指针,指向可变参的列表,用于声明变量
//         eg. va_list ap;
//     va_start
//         获取可变参数列表的第一个参数的地址, para为可变参数最左边的参数,即...之前的最后一个参数
//         eg. va_start(ap, para)
//     va_arg
//         获取可变参数的当前参数并将指针指向下一参数, type为当前参数的类型
//         eg. va_arg(ap, type)
//     va_end
//         与清空va_list的参数列表,与va_start配合使用
//         eg. va_end(ap)
//     va_copy
//         复制 va_list 的变量
//         eg. va_copy(des, src)
