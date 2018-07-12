
    函数模板遇上函数重载

    函数模板和普通函数的区别：函数模板是不允许自动类型转换的，而普通函数允许自动类型转换

    当函数模板和普通函数在一起时，调用规则如下：

        函数模板可以像普通函数一样被重载
        c++编译器优先考虑普通函数
        如果函数模板可以产生一个更好的匹配，那么选择模板
        可以通过空模板实参列表的语法，限定编译器只通过模板匹配

   下面我将通过代码来演示这个过程：

    #include <iostream>
    using namespace std;
     
    template <typename T>
    void myswap(T &a, T &b)
    {
    	T t;
    	t = a;
    	a = b;
    	b = t;
    	cout<<"myswap 模板函数do"<<endl;
    }
     
    void myswap(char &a, int &b)
    {
    	int t;
    	t = a;
    	a = b;
    	b = t;
    	cout<<"myswap 普通函数do"<<endl;
    }
     
    int main()
    {
    	char cData = 'a';
    	int  iData = 2;
     
    	myswap<int>(cData, iData);  //结论 函数模板不提供隐式的数据类型转换  必须是严格的匹配
     
    	//myswap(cData, iData); 
    	//myswap(iData, cData);
    	
    	cout<<"hello..."<<endl;
    	return 0;
    }

编译器会对函数模板进行两次编译：在声明的地方对模板代码本身进行编译，在调用的地方对参数替换后的代码进行编译。
