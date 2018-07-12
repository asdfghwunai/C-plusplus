char* mystrcpy(char* dst, const char* src)
{
    assert(dst != NULL);
    assert(src != NULL);
 
    if (dst == src)
        return dst;
 
    int size = strlen(src) + 1;
 
    if (dst < =src || src + size <= dst)
    {
        char* d = dst;
        const char* s = src;
 
        while (size--)
            *d++ = *s++;
    }
    else
    {
        char* d = dst + size - 1;
        const char* s = src + size - 1;
 
        while (size--)
            *d-- = *s--;
    }
    return dst;
}
