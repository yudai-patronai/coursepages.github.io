#include <stdio.h>
#include <stdlib.h>

#define abs(x) ((x)<0 ? -(x) : (x))
#define N 1000
struct Telo {
	float h;
	float w;
};

void print(struct Telo p) {
	// printf("%d\t%d\t%d\t%d\n", p.chest, p.waist, p.hip, deviation(&p));
	printf("%.2f %.3f\n", p.h, p.w);
}
int cmp(const void * p1, const void * p2)
{
	struct Telo * px = (struct Telo*)p1;
	struct Telo * py = (struct Telo*)p2;
    float res;
	
	if (px->w != py->w) {
		res=  px->w - py->w;
	} else
        res =  py->h - px->h;
    if (res==0)
        return 0;
    return res < 0 ? -1 : 1;
}
int main()
{
	int n, i;
	struct Telo a[N];
	
	scanf("%d", &n);
	int res;
	for (i=0; i<n; i++) {
		if (2!=(res=scanf("%f%f", &(a[i].h), &(a[i].w)))) {
			fprintf(stderr, "ERROR: too few data - only %d data for i=%d\n", res, i);
			return 7;
		}
	}		

	qsort(a, n, sizeof(struct Telo), cmp);
	for (i=0; i<n; i++) {
		print(a[i]);
	}	
	return 0;
}
