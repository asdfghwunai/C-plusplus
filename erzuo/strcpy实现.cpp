#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;


char *mystrcpy(char *dst,char *src)
{
    assert(dst!=NULL&&src!=NULL);

    int size=strlen(src)+1;   //测长
    if(dst<=src||dst>src+size-1)     //无重叠，从前到后
    {
        char *s=src;
        char *d=dst;
        while(size--)
        {
            *dst++=*src++;
        }
    }
    else                //无重叠，从后到前
    {
        char *s=src+size-1;
        char *d=dst+size-1;
        while(size--)
        {
            *dst--=*src--;
        }
    }
    return dst;

}
