#include <stdio.h>
#include <stdlib.h>

#define N 1000
int cmp(const void * p1, const void * p2)
{
    int x = *(int*)p1;
    int y = *(int*)p2;
    do {
        // printf("x=%d (%d) y=%d (%d)\n", x, x%10, y, y%10);
        if (x%10 != y%10)
            return x%10 - y%10;
        x /= 10;
        y /= 10;
        // printf("x=%d y=%d\n---\n", x, y);
    } while (x!=0 && y!=0);
	return x-y;
}
int main()
{
    // int x=23, y=123;
    // cmp(&x, &y);
    // x = 43, y = 23;
    // cmp(&x, &y);
    // return 0;
	int n, i;
	int a[N];
	
	scanf("%d", &n);
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);

	qsort(a, n, sizeof(int), cmp);
	for (i=0; i<n; i++) {
		printf("%d ", a[i]);
	}	
	printf("\n");
	return 0;
}
