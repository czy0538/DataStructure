#include <stdio.h>
#include <time.h>
#include <clock.c>
int main()
{
    int n, i;
    unsigned long long factorial = 1;

    scanf("%d", &n);

    begin();
    // 如果输入是负数，显示错误
    if (n < 0)
        printf("Error! 负数没有阶乘jiechen");

    else
    {
        int j=0;
        for(j=0;j<1000;j++)
        {
            for (i = 1; i <= n; ++i)
            {
                factorial *= i; // factorial = factorial*i;
            }
            printf("%d! = %llu", n, factorial);
        }

    }
    end();
    getchar();
    getchar();
    return 0;
}
