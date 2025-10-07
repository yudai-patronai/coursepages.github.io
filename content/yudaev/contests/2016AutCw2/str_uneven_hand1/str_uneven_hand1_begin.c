#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N 1000
char* convert(const char * str);

int main()
{
	char s[N];
	fgets(s, N, stdin);
	int len = strlen(s);
	if (s[len-1]=='\n')
		s[len-1]=0;
	len = strlen(s);
 	if (s[len-1]=='\r')
		s[len-1]=0;
    char * str = convert(s);
    printf("/%s/\n", s);
    printf("[%s]\n", str);
    
    free(str);
	return 0;
}



