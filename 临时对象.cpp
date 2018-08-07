/*
https://blog.csdn.net/happysujia/article/details/51298985
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
CTemp& operator=(const CTemp& t)改为CTemp& operator=(const CTemp& t)，因为函数确实返回一个const类型的临时对象，但是没有调用copy构造函数啊
