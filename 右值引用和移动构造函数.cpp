参考
https://mp.weixin.qq.com/s?__biz=MzIwNTc4NTEwOQ==&mid=2247483724&idx=1&sn=e6b4304547607ba7d7714716913f5259&chksm=972ad036a05d592076dc6f37a3df5cc5ee18678eae56c35d5008c7ff046ec5239b5bf55eb9c0&mpshare=1&srcid=0825UmZbQZ3YCp4bvw8rWvlT&scene=21#wechat_redirect

1.对于一个表达式，只要可以取址的就叫左值
int x = 4;
int* p = &x;          //ok, x 是左值

int& fun();
fun() = 42; 	     // ok, fun() 是左值
int* p1 = &fun();    // ok, fun() 是左值

int foo();
int j = 0;
j = foo();            // ok, foo() 是右值
int* p2 = &foobar();  // 错误，不能获取右值的地址
j = 42;               // ok, 42 是右值

2.参数
void fun(int & i)    //函数（1） ，左值引用作参数
{ 
	cout << "int & " << endl; 
}

void fun(int && i)  //函数（2）， 右值引用作参数
{ 
	cout << "int && " << endl; 
}
//-------------------------
int i = 12;
foo(i);      //输出 int &
foo(22);      //输出 int &&

3.移动构造函数采用右值引用做参数，和const 左值引用一样都不能改变值，这个函数是浅拷贝，只是把内存偷过来
Test(Test && rhs):m_p(rhs.m_p)  //偷过来了
{
    rhs.m_p = nullptr;
}
