#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000
int cmp(const void * p1, const void * p2)
{
	return *(char*)p1 - *(char*)p2;
}
int main()
{
	char a[N+1];
	
	fgets(a,N,stdin);
    char * s = strchr(a,'.');
    *s=0;

	qsort(a, strlen(a), sizeof(char), cmp);
    printf("%s.", a);
	
	printf("\n");
	return 0;
}
