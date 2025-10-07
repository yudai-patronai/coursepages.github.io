#include <stdio.h>
#include <stdlib.h>

#define abs(x) ((x)<0 ? -(x) : (x))
#define N 1000
struct Telo {
	int chest;
	int waist;
	int hip;
};

int deviation(struct Telo * p)
{
	return abs(p->chest-90)+abs(p->waist-60)+abs(p->hip-90);
}
void print(struct Telo p) {
	// printf("%d\t%d\t%d\t%d\n", p.chest, p.waist, p.hip, deviation(&p));
	printf("%d %d %d\n", p.chest, p.waist, p.hip);
}
int cmp(const void * p1, const void * p2)
{
	struct Telo * px = (struct Telo*)p1;
	struct Telo * py = (struct Telo*)p2;
	int dx = deviation(px);
	int dy = deviation(py);
	
	if (dx!=dy) {
		return dx-dy;
	} else if ( px->chest != py->chest) {
		// printf("Compare chests\n");
		// print(*px);
		// print(*py);
		return (py->chest - px->chest);
	}
	else if ( px->waist != py->waist) {
		// printf("Compare waist\n");
		// print(*px);
		// print(*py);
		return px->waist - py->waist;
	} else {
		return -(px->hip - py->hip);
	}
}
int main()
{
	int n, i;
	struct Telo a[N];
	
	scanf("%d", &n);
	int res;
	for (i=0; i<n; i++) {
		if (3!=(res=scanf("%d%d%d", &(a[i].chest), &(a[i].waist), &(a[i].hip)))) {
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
