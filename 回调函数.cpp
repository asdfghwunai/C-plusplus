//就是你调用一个函数,这个函数又调用另一个

#include <iostream>

typedef void (*Fun)(int);//定义一个函数指针类型
Fun p = NULL;//用Fun定义一个变量p，它指向一个返回值为空参数为int的函数

void caller(Fun pCallback)
{
    p = pCallback;

    //达成某一条件后，通过名片（函数指针p），传回结果
    int result = 1;

    (*p)(result);
}


void callback(int a)//回调函数
{
    std::cout << "callback result = " << a << std::endl;
}

int main(int argc, char* argv[])
{
    caller(callback);

    getchar();
    return 0;
} 
