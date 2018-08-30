const char* node1="abc";    
char* const node1="abc";    

node1[2]='k';     //编译错误，改*p错误
node2[2]='k';     //运行错误，改*p可以，但是指向不可改

node1="xyz";     //正确
node2="xyz";      //编译错误，想改指针

//综上，char * 和 const char *都可以接收字符串常量，string对象的c_str()返回一个const char *p，可能p是指针，可以被const指针和普通指针接收


//========================================================================
const引用就很严格，只有一种const int & a,没有int & const a;

int b=1;
const int &a=b;  //这步对，可以指向
a=2; //错误
b=2; //正确

const int c=3;
int &d=c;   //直接错，因为有风险会更改c
