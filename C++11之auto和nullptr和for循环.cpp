/*
auto可以自动推导类型，但是不能用auto来声明函数，但是和定义函数放一起就可以声明
*/

//示例代码1.0 http://www.cnblogs.com/feng-sc/p/5710724.html
auto AddTest(int a, int b)    //声明加定义
{
    return a + b;
}

int main()
{
    auto index = 10;
    auto str = "abc";
    auto ret = AddTest(1,2);
    std::cout << "index:" << index << std::endl;
    std::cout << "str:" << str << std::endl;
    std::cout << "res:" << ret << std::endl;
}


//=====================================

/*
NULL不安全，会被当成整数0
*/

//示例代码1.0 http://www.cnblogs.com/feng-sc/p/5710724.html
class Test
{
public:
    void TestWork(int index)
    {
        std::cout << "TestWork 1" << std::endl;
    }
    void TestWork(int * index)
    {
        std::cout << "TestWork 2" << std::endl;
    }
};

int main()
{
    Test test;
    test.TestWork(NULL);
    test.TestWork(nullptr);
}

//=================================
/*
一种更简洁的写法
*/

//示例代码1.0 http://www.cnblogs.com/feng-sc/p/5710724.html
int main()
{
    int numbers[] = { 1,2,3,4,5 };
    std::cout << "numbers:" << std::endl;
    for (auto number : numbers)
    {
        std::cout << number << std::endl;
    }
}
