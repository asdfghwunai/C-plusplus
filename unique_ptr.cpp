(1)auto_ptr和unique_ptrc采用的是ownership(建立所有权)概念，对于特定对象，只能被一个智能指针所拥有，这样，只有拥有该对象的智能指针的析构函数
才会删除该对象，然后，要注意的是，赋值操作会转让操作权。
虽然auto_ptr和unique_ptr都采用该策略，但是unique_ptr的策略更严格。当出现上述情况时，程序会编译出错，而auto_ptr则会在执行阶段core dumped。
(2)shared_ptr则采用reference counting(引用计数)的策略，例如，赋值时，计数+1，指针过期时，计数-1.只有当计数为0时，即最后一个指针过期时，才会被析构掉


//test2
auto_ptr<Report> p1[5] =
    {
        auto_ptr<Report> (new Report("using auto_ptr")), 
        auto_ptr<Report> (new Report("using auto_ptr")), 
        auto_ptr<Report> (new Report("using auto_ptr")), 
        auto_ptr<Report> (new Report("using auto_ptr")), 
        auto_ptr<Report> (new Report("using auto_ptr")) 
    };
    auto_ptr<Report> p2 = p1[2];//#1
    for(int i=0; i<5; ++i)
    {
        p1[i]->comment();
    }
    
    
    [root@server10 auto_ptr]# ./t 
Object created
Object created
Object created
Object created
Object created
using auto_ptr 0
using auto_ptr 1
Segmentation fault (core dumped)

类似test2代码，(p1[2]将Report对象的所有权转交给p2，而p1[2]此时为空指针，这样要打印p1[2]的值时，造成了core dumped的意外)
将test2中的auto_ptr使用unique_ptr代替后，编译器直接报上述错误,可见编译器认为#1非法，避免了将p1[2]指向无效数据的情况。
这也是容器算法禁止使用auto_ptr,但是允许使用unique_ptr的原因。 
