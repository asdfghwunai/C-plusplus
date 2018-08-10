//示例代码1.0 http://www.cnblogs.com/feng-sc/p/5710724.html
int main()
{
    auto add= [](int a, int b)->int{
        return a + b;
    };
    int ret = add(1,2);
    std::cout << "ret:" << ret << std::endl;
    return 0;
}

/*
普通的，
lamda表达式是一个匿名函数，居然可以写在式子里，后面有；
*/
============================
int main()
{
    Test test;
    test.Add(add, 1, 2);

    TestAdd testAdd;
    test.Add(std::bind(&TestAdd::Add, testAdd, std::placeholders::_1, std::placeholders::_2), 1, 2);

    test.Add([](int a, int b)->int {
        std::cout << "lamda add fun" << std::endl;
        return a + b;
    },1,2);
    return 0;
}
/*
函数对象

[]：中括号用于控制main函数与内，lamda表达式之前的变量在lamda表达式中的访问形式
可以看https://blog.csdn.net/lsjseu/article/details/50770637
*/
