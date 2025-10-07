#include <ctype.h>
char* convert(const char * str)
{
    char * res = calloc(strlen(str)+1, 1);
    int i;  
    for(i=0; str[i]; i++) {
        int x = str[i];
        res[i] = i%2 ? tolower(x) : toupper(x);
    }
	res[i]=0;
    return res;
}
