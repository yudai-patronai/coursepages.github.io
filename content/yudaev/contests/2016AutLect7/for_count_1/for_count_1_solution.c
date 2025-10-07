#include <stdio.h>

int main()
{
	int i, k, n, x;
	long res;
	
	scanf("%d", &x);
	res = 0;
	do {
		if (x%2!=0)
			res++;
		x = x/2;
	} while(x>0);
	
	printf("%ld\n", res);
	return 0;
}	