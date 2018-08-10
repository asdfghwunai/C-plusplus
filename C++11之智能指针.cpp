//shared_ptr
//示例代码1.0 http://www.cnblogs.com/feng-sc/p/5710724.html
#include <memory>
class Test
{
public:
    Test()
    {
        std::cout << "Test()" << std::endl;
    }
    ~Test()
    {
        std::cout << "~Test()" << std::endl;
    }
};
int main()
{
    std::shared_ptr<Test> p1 = std::make_shared<Test>();       //封装了new
    std::cout << "1 ref:" << p1.use_count() << std::endl;
    {
        std::shared_ptr<Test> p2 = p1;
        std::cout << "2 ref:" << p1.use_count() << std::endl;
    }
    std::cout << "3 ref:" << p1.use_count() << std::endl;
    return 0;
}

/*
输出1,2,3

当main函数退出后，p1离开main函数的作用域，此时p1被销毁，当p1销毁时，检测到引用计数已经为1，
就会在p1的析构函数中调用delete之前std::make_shared创建的指针。

shared_ptr会出现循环引用，里面的成员指针换成weak_ptr；
*/

