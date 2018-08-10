/*
用函数指针是只能接收外部函数，不能接收类里定义函数，
*/

//示例代码1.0 http://www.cnblogs.com/feng-sc/p/5710724.html

class Test
{
public:
    void Add(std::function<int(int, int)> fun, int a, int b)
    {
        int sum = fun(a, b);
        std::cout << "sum:" << sum << std::endl;
    }
};

int add(int a,int b)
{
    std::cout << "add" << std::endl;
    return a + b;
}

class TestAdd
{
public:
    int Add(int a,int b)
    {
        std::cout << "TestAdd::Add" << std::endl;
        return a + b;
    }
};

int main()
{
    Test test;
    test.Add(add, 1, 2);     //接收外部函数

    TestAdd testAdd;
    test.Add(std::bind(&TestAdd::Add, testAdd, std::placeholders::_1, std::placeholders::_2), 1, 2); 
                //std::placeholders::_1和std::placeholders::_2为参数占位符，表示std::bind封装的可执行对象可以接受两个参数。数量我感觉任意
    return 0;
}

