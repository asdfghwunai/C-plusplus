/*
 适配器模式（Adapter）：将一个类的接口转换成客户希望的另外一个接口。A d a p t e r 模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。

适用场景：
1、已经存在的类的接口不符合我们的需求；
2、创建一个可以复用的类，使得该类可以与其他不相关的类或不可预见的类（即那些接口可能不一定兼容的类）协同工作；
3、在不对每一个都进行子类化以匹配它们的接口的情况下，使用一些已经存在的子类。

说白了：其实就好比，你的苹果充电器是香港买的三孔插头，但是你现在在国内，只有二孔插座，那么适配器就是让你的三孔插头变成二孔插头，然后成功和二孔插座适配
*/

#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
 
 
class Person                       //作为下面的类型
{
public:
	Person(string name, int age) :name(name), age(age) {}
	string name;
	int age;
 
};
struct MyPrint:public binary_function<Person,int,void>     //作为适配器的模板类型
{
	void operator()(const Person p1, int val1) const
	{
		cout << "name:" << p1.name << " age:" << p1.age + val1 << endl;
	}
};
 
template<class _Fn2>
class MyBind2nd
{
public:
	MyBind2nd(typename _Fn2 Op, typename _Fn2::second_argument_type v)     //_Fn2现在是作为类型作用域，Op是对象
	{
		this->Op = Op;
		this->_Value = v;
	}
	typename _Fn2::result_type operator()(typename _Fn2::first_argument_type val)
	{
		return this->Op(val, this->_Value);    			//一切皆对象
	}
private:
	typename _Fn2 Op;
	typename _Fn2::second_argument_type _Value;
};
 
 
template<class _Fn2,class _Fy>
MyBind2nd<_Fn2> MyBinder(_Fn2  m, _Fy val)    //这是个函数
{
	return MyBind2nd<_Fn2>(m, val);            //这是个对象
}
 
int main(void)
{
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	for_each(v.begin(), v.end(), MyBinder(MyPrint(),100));   //用MyBinder是不是有个自动推导类型呢？
	
	cout << endl;
	system("pause");
	return 0;
}
