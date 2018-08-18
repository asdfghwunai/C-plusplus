/*
传参全声明为const
拷贝构造函数不用销毁内存，直接就是从头开始创建新对象
赋值运算符需要销毁，是覆盖老对象的内容
*/

#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;


class String
{
public:
    String(const char *s);
    String(const String& other);
    String& operator=(const String& other);

    ~String();

private:
    char *str;
};


String::String(const char *s)
{
    if(s==NULL)
    {
        str=(char *)malloc(1);
        *str='\0';
    }
    else
    {
        str=(char *)malloc(sizeof(strlen(s)+1));
        strcpy(str,s);
    }
}

String::~String()    //编程太渣了，这里都写错了
{
    free(str);
    str=NULL;
}

String::String(const String& other)
{
    if(this==&other)
        return;
    //free(str);   //注意拷贝构造函数刚开始没有建对象，就是直接调用的
    //str=NULL;
    str=(char *)malloc(sizeof(strlen(other.str)+1));
    strcpy(str,other.str);
}

String& String::operator=(const String& other)
{
    if(this==&other)
        return *this;

    free(str);   //释放以前的,这时以前的对象就有东西了
    str=NULL;
    str=(char *)malloc(sizeof(strlen(other.str)+1));
    strcpy(str,other.str);
    return *this;     //难道就是多了一个返回？
}


int main()
{
    const char *str="123";
    String s1(str);
    String s2(s1);

    s2=s1;


    return 0;
}
