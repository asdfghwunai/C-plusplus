/*
 这个其实就是我们迭代器模式的精髓：提供一种方法顺序访问一个聚合对象中各个元素, 而又不需暴露该对象的内部表示。
 
 适用性：
 
1．访问一个聚合对象的内容而无需暴露它的内部表示。 
2．支持对聚合对象的多种遍历。 
3．为遍历不同的聚合结构提供一个统一的接口(即, 支持多态迭代)。
*/

//用模板串起来

#include <iostream>
#include <vector>
using namespace std;
 
template<class Item>
class Iterator                         //迭代器类
{
public:
    virtual void first()=0;
    virtual void next()=0;
    virtual Item* currentItem()=0;
    virtual bool isDone()=0;
    virtual ~Iterator(){}
};
 
template<class Item>
class ConcreteAggregate;             //这是提前声明吗？
 
template<class Item>
class ConcreteIterator : public Iterator <Item>    //迭代器类子类实现
{
    ConcreteAggregate<Item> * aggr;
    int cur;
public:
    ConcreteIterator(ConcreteAggregate<Item>*a):aggr(a),cur(0){}
    virtual void first()
    {
        cur=0;
    }
    virtual void next()
    {
        if(cur<aggr->getLen())
            cur++;
    }
    virtual Item* currentItem()
    {
        if(cur<aggr->getLen())
            return &(*aggr)[cur];
        else
            return NULL;
    }
    virtual bool isDone()
    {
        return (cur>=aggr->getLen());
    }
};
 
template<class Item>
class Aggregate                      //容器类
{
public:
    virtual Iterator<Item>* createIterator()=0;
    virtual ~Aggregate(){}
};
 
template<class Item>
class ConcreteAggregate:public Aggregate<Item>      //容器子类实现
{
    vector<Item >data;
public:
    ConcreteAggregate()
    {
        data.push_back(1);
        data.push_back(2);
        data.push_back(3);
    }
    virtual Iterator<Item>* createIterator()       //虚函数，  Iterator<Item>*是父类，有个向上转型        
    {
        return new ConcreteIterator<Item>(this);      //只是想得到一个迭代器对象的指针
    }
    Item& operator[](int index)              //直接重载【】
    {
        return data[index];
    }
    int getLen()
    {
        return data.size();
    }
};
 
int main()
{
    Aggregate<int> * aggr =new ConcreteAggregate<int>();
    Iterator<int> *it=aggr->createIterator();  
 
    for(it->first();!it->isDone();it->next())
    {
        cout<<*(it->currentItem())<<endl;
    }
    delete it;
    delete aggr;
    return 0;
}
