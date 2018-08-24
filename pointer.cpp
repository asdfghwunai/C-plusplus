//=====数组指针与一维数组======

char a[5]={1,2,3,4,5};
char (*p3)[5]=&a;    //也可以指向一维
char (*p4)[5]=(char (*)[5])a;    //Clion必须强制类型转换一下，不然编辑阶段出错

cout<<&a<<" "<<p3+1<<" "<<p4+1<<endl;   //0x7ffce31b1880 0x7ffce31b1885 0x7ffce31b1885
//======数组指针与二维数组======
int a[5][5];
int (*p)[4];
p=(int (*)[4])a;  //Clion必须强制类型转换一下

printf("%p %d",&p[4][2]-&a[4][2],&p[4][2]-&a[4][2]);   //0xfffffffffffffffc -4
/*---方法--
int (*p)[4]已说明加一次跳过4个int，还要注意指针加减是以元素为单位

p代表整个数组对象的地址，*p代表首元素的地址，*(*p+i)就代表一维数组中第i个数

二维数组==数组指针---一维指针--元素
指针数组==二维指针----一维指针----元素
*/

//===a和&a====
int a[5]={1,2,3,4,5};

int *p1=(int *)(&a+1);
int *p2=(int *)((int)a+1);    //CLion又通不过，int *转int报错

printf("%x %x",*(p1-1),*p2);  //5  0x200 00 00
/*--方法---
第一个好说
第二个先写出a的数组内存分配，小端模式下由低地址到高地址: 01 00 00 00,02 00 00 00,03 00 00 00....
int(a)+1 是从第一个元素的第二个字节处开始取为 00 00 00 02，所以*p2为0x2 00 00 00
*/

//=====一维数组的形参=======
char a[]; 
char *b;
void fun(char *p)
void fun(char p[100])
void fun(char p[])
  
//=====二维数组的形参=======
char a[3][4];
void fun(char (*p)[4])
void fun(char a[][4])

//====指针数组的形参====
char *a[5];
void fun(char **p)
  
//====函数指针=====
(*(void (*p)())0)()  
/*---方法----
这里注意一个运算符优先级问题 强制类型和*是一个级别，但结合方向从右到左
*/
  
//----函数指针------fun是个变量，不是函数啊
char * (*fun)(char *p);
/*--一级就构建成功-----*/

//----函数指针数组-----
char * (*fun[3])(char *p);
//*fun[3] 就是一个数组，挺简单的进化到指针数组
/*--一级建指针，二级建数组----*/

//----函数指针数组指针-----
char * (* (*fun)[3])(char *p);
/*---先建建数组指针，一个指针指向这个数组指针，数组里的元素是函数指针---*/
 
//----动态建立二维数组---
 //为邻接矩阵开辟空间和赋初值
   arc = new int*[this->vexnum];
   dis = new Dis[this->vexnum];
   for (int i = 0; i < this->vexnum; i++) {
     arc[i]=new int[this->vexnum];
   }

//=========面试题====
/*-----1--------*/
char *p[]={"TENCENT","CAMPUS","RECRUITING"};
char **pp[]={p+2,p+1,p};   //对象是二级指针
char ***ppp=pp;   //指向三级指针

printf("%s",**++ppp);   //解引到一级
printf("%s",*++*++ppp); //解引到一级
//"CAMPUS" "CAMPUS"
