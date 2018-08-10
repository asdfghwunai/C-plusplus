/*
std::array跟数组并没有太大区别，对于多维数据使用std::array，个人反而有些不是很习惯吧。

std::array相对于数组，增加了迭代器等函数
*/

//示例代码1.0 http://www.cnblogs.com/feng-sc/p/5710724.html
#include <array>
int main()
{
    std::array<int, 4> arrayDemo = { 1,2,3,4 };
    std::cout << "arrayDemo:" << std::endl;
    for (auto itor : arrayDemo)
    {
        std::cout << itor << std::endl;
    }
    int arrayDemoSize = sizeof(arrayDemo);
    std::cout << "arrayDemo size:" << arrayDemoSize << std::endl;
    return 0;
}


//===========================================================
/*
remove   算法描述：查找的得到第一个元素的位置，然后从此位置开始遍历容器，将后面的元素依次前移，跳过和value相同值的元素，也就是说，
所有和value相同值的元素都会被覆盖，而其他的元素都会依次前移。最后remove返回"指向最后一个   '有用'   元素的iterator",但是在remove算法过程中，
并没有修改原容器的size,以及end()。但是从逻辑角度看，最后的[   从remove得到的iterator---_result,   容器的结尾end()   )   
这个区间里面的元素已经没有意义了。所以这些元素不应该属于该容器了。remove算法能做的仅此而已，并没有删除这些无用的元素。    
 结论：移除容器里面的元素不应该使用remove算法，而是容器自己的方法erase()。
 
 vector<int> v;						// 正如从前
v.erase(remove(v.begin(), v.end(), 99), v.end());		// 真的删除所有
							// 等于99的元素
cout << v.size();						// 现在返回7

STL中唯一名叫remove又能从容器中除去元素的函数：
list<int> li;			// 建立一个list
				  // 放一些值进去
li.remove(99);			// 除去所有等于99的元素：
				// 真的删除元素，
				// 所以它的大小可能改变了

*/


//示例代码1.0 http://www.cnblogs.com/feng-sc/p/5710724.html
#include <forward_list>
int main()
{
    std::forward_list<int> numbers = {1,2,3,4,5,4,4};
    std::cout << "numbers:" << std::endl;
    for (auto number : numbers)
    {
        std::cout << number << std::endl;
    }
    numbers.remove(4);
    std::cout << "numbers after remove:" << std::endl;
    for (auto number : numbers)
    {
        std::cout << number << std::endl;
    }
    return 0;
}

//=====================================================
//std::unordered_map内部是哈希表的实现方式

//webset address: http://www.cplusplus.com/reference/unordered_map/unordered_map/bucket_count/
#include <iostream>
#include <string>
#include <unordered_map>
int main()
{
    std::unordered_map<std::string, std::string> mymap =
    {
        { "house","maison" },
        { "apple","pomme" },
        { "tree","arbre" },
        { "book","livre" },
        { "door","porte" },
        { "grapefruit","pamplemousse" }
    };
    unsigned n = mymap.bucket_count();
    std::cout << "mymap has " << n << " buckets.\n";
    for (unsigned i = 0; i<n; ++i) 
    {
        std::cout << "bucket #" << i << " contains: ";
        for (auto it = mymap.begin(i); it != mymap.end(i); ++it)
            std::cout << "[" << it->first << ":" << it->second << "] ";
        std::cout << "\n";
    }
    return 0;
}

//============================================================
//std::unordered_set的数据存储结构也是哈希表的方式结构

//示例代码1.0 http://www.cnblogs.com/feng-sc/p/5710724.html
#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
int main()
{
    std::unordered_set<int> unorder_set;
    unorder_set.insert(7);
    unorder_set.insert(5);
    unorder_set.insert(3);
    unorder_set.insert(4);
    unorder_set.insert(6);
    std::cout << "unorder_set:" << std::endl;
    for (auto itor : unorder_set)
    {
        std::cout << itor << std::endl;
    }

    std::set<int> set;
    set.insert(7);
    set.insert(5);
    set.insert(3);
    set.insert(4);
    set.insert(6);
    std::cout << "set:" << std::endl;
    for (auto itor : set)
    {
        std::cout << itor << std::endl;
    }
}

