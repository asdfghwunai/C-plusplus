/*
https://blog.csdn.net/happysujia/article/details/51298985

博客的意思是你只要return首先生出一个临时对象(还调用自己的拷贝构造函数)，后面再根据实际确定调不调用拷贝或赋值操作。。。
实际情况好复杂，我是看不出规律啊
*/


#include <stdio.h>
class CTemp
{
public:
    int a;
public:
    CTemp(const CTemp& t) //Copy Ctor!
    {
        printf("Copy Ctor!\n");
        a = t.a;
    };
    CTemp& operator=(const CTemp& t) //Assignment Copy Ctor!
    {
        printf("Assignment Copy Ctor!\n");
        a = t.a;
        return *this;
    }
    CTemp(int m = 0);
    virtual ~CTemp(){};
};
CTemp::CTemp(int m) //Copy Ctor!
{
    printf("Construct function!\n");
    a = m;
    printf("a = %d\n",a);
}
CTemp Double(CTemp& ts)
{
    CTemp tmp;      //构建一个临时对象
    tmp.a = ts.a*2;
    return tmp;

}
//-------------Main函数-----------------
int main()
{
    CTemp tm(10),sum;
    printf("\n\n");

    sum = Double(tm);


    printf("\n\nsum.a = %d \n",sum.a);

    return 0;
}

博客上说:
 Output:
Construct function!
a = 10
Construct function!
a = 0

Construct function!
a = 0
Copy Ctor!
Assignment Copy Ctor!

sum.a = 20

但是在CLION上：
a = 10
Construct function!
a = 0


Construct function!
a = 0
Assignment Copy Ctor!


sum.a = 20 

改动:
CTemp& operator=(CTemp& t)改为CTemp& operator=(const CTemp& t)，因为函数确实返回一个const类型的临时对象，但是没有调用我定义的copy构造函数啊
生成临时对象过程中没有调用拷贝构造函数来生成，应该是调用其他函数来生成，这就说的通了。

至于为什么和人家的不一样，恐怕有优化过程，你闲的时候看看 https://segmentfault.com/q/1010000007647491

但是也有说
    老式编译器上无此要求，现代编译器上拷贝、赋值的标准形式如下（在类X中的声明）：
    X(const X& rhs);
    X& operator=(const X& rhs); 
所以报错原因可能不是它确实生出const临时对象了，也可能没生出
好麻烦，到底生出没生出临时对象呢？
