#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define N 1000
char*  read_str();
char* replace_1(const char * str, const char * from, const char * to);

int main()
{
	char *s;
	char *from;
	char *to;
    char * res;
    
    s = read_str();
    from = read_str();
    to = read_str();
    
    res = replace_1(s, from, to);

    printf("[%s]\n", s);
    if (res == NULL)
        printf("NULL\n");
    else 
        printf("[%s]\n", res);
    
    free(res);
    free(to);
    free(from);
    free(s);
    
	return 0;
}
#define N 1000
char * read_str()
{
    char s[N+1];
    fgets(s, N, stdin);
    // printf("s=/%s/\n", s);
    char * from = strchr(s, '[');
    assert(from!=NULL);
    from ++;
    // printf("f=/%s/\n", from);
    char * to = strrchr(s, ']');
    assert(to!=NULL);
    *to = 0;
    // printf("f=/%s/\n", from);
    return strdup(from);
}
#line 1000001
