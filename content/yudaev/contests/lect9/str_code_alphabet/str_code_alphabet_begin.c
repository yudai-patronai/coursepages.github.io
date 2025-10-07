#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define N 100

char * code (char * dst, char * src, char * alphabetA, char * alphabetB) ;

void trim(char * s)
{
	char * p;
	for(p=s+strlen(s)-1; p>=s && isspace(*p); p--)
		*p='\0';
}	

int main()
{
	char a[N], b[N];
	char alA[N];
	char alB[N];
	
	fgets(a,N,stdin);
	trim(a);
	fgets(alA,N,stdin);
	trim(alA);
	fgets(alB,N,stdin);
	trim(alB);
	
	printf("[%s]\n", a);
	printf("(%s)\n", code(b,a,alA,alB));
	return 0;
}
