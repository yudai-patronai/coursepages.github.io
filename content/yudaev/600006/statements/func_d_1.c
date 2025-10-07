#include <stdio.h>
#include <math.h>

double perimeter(double x1, double y1, double x2, double y2, double x3, double y3);

int main(void) {
	double x1, y1, x2, y2, x3, y3;
	scanf("%lg %lg %lg %lg %lg %lg", &x1, &y1, &x2, &y2, &x3, &y3);
	printf("%lg\n", perimeter(x1, y1, x2, y2, x3, y3));
	return 0;
}
