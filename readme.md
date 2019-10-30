# 数据结构笔记

## 0C&C++知识补充

### 1.变长参数表

- 存在于头文件 stdarg.h / cstdarg中

- 省略号表示参数表中的参数的数量和类型都是可变的。

- 省略号只能出现在参数表的尾部。
- va_list 声明一个变量，该变量依次引用各个参数，一般成为ap，意为参数指针
- va_start 将ap初始化为指向第一个无名参数的指针，在使用ap之前，该宏必须被调用因此。**参数表必须至少包括一个有名参数**，va_start将最后一个有名参数作为起点
- 每次调用va_arg，将返回一个参数，并将ap指向下一个参数。va_arg(ap,int)来决定返回的对象类型，指针移动的步长。
- 最后必须在函数返回前调用va_end

### 2.行列指针

```cpp
#include<iostream>
using namespace std;
int main()
{
	int a[3][4];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			a[i][j] = i * 10 + j;
		}
	}
	cout << *a << endl;//0019F93C,a为行指针，他的取值为行地址
	cout << **a << endl;//0
	cout << *(a + 1) << endl;//0019F94C
	int* p0 = a[0];
	int* p1 = a[1];
	cout << p0 << endl;//0019F93C
	cout << p1 << endl;//0019F94C
	cout << *p0 << endl;//0
	cout << *p1 << endl;//10
	cout << *(++p1) << endl;//11
	return 0;
}
```





## 1绪论

###  1.1 数据结构及其讨论范畴

- 程序设计=算法（处理问题的策略）+数据结构（问题的数学模型）
- 数据结构是一门讨论“描述现实世界实体的数学模型及其上的操作在计算机中如何表示和实现”的学科
- 对于每一种数据结构，主要讨论如下三个方面的问题：
  - 数据的逻辑结构
  - 数据的存储结构（物理结构）
  - 数据的运算(基本操作)

### 1.2 基本概念和术语

- 数据：信息的载体，能被计算机识别、存储和加工处理。（整数，实数，字符串，图像......）
- 数据元素：数据的**基本单位**。在计算中常被作为一个整体考虑和处理。（如一个学生的信息）
- 数据项：数据不可分割的**最小单位**，如学号。
- 数据对象：性质相同的数据元素的集合，如一个班级的学生的信息的集合。
- 数据结构类型：
  - 线性结构：除第一个元素和最后一个元素之外，其他元素都有且只有一个直接前驱，有且只有一个直接后继。（线性表，栈，队列，串，数组，广义表）
  - 非线性结构：一个节点可能有多个直接前驱和直接后继（树，图）
- 数据元素的存储结构分为顺序存储和非顺序存储（链式存储）

### 1.3 抽象数据类型(ADT)的表示与实现

- 定义：是一个数学模型和在该模型上定义的操作的集合
- 包括：数据对象，数据对象中各元素的关系，一组基本操作
- 软件设计：是对数据结构、操作过程、控制机能的抽象
- 抽象数据类型的规格描述：
  - 完整性：反映所定义的抽象数据类型的全部特征
  - 统一性：前后协调，不自相矛盾
  - 通用性：适用于尽量广泛的对象
  - 不依赖性：不依赖于程序设计语言
- 规格描述的两个方面：
  - 语法：给出操作的名称、I/O参数和类型
  - 语义：由一组等式组成，定义各种操作的功能以及相互之间的关系

### 1.4 算法和算法分析

- 概念：对问题求解过程的一种描述，是为解决一个或一类问题给出的一个确定的、有限长的操作序列。
- 算法的五个重要特性：
  - 有穷性：操作步骤为有限个，且每个步骤都能在有限的时间内完成
  - 确定性：组成算法的操作必须清晰无二义性
  - 可行性：算法的全部操作必须足够基本，都可以通过已经实现的基本操作的有限次运算实现
  - 输入
  - 输出
- 算法设计的原则
  - 必须是正确的：除了满足各种功能外，还应对各种输入得出正确的结果
  - 应该有很好的可读性
  - 必须具有健壮性：算法对非法输入的数据做出恰当的反映或进行相应处理
  - 算法的效率：具有高效率与低存储量。
- 影响时间特性的四个因素：
  - 输入的数据的总量
  - 对源程序编译所需的时间
  - 执行每条指令所需的时间
  - 指令重复执行的次数
- 评价算法的标准：求解问题的基本操作的执行次数





