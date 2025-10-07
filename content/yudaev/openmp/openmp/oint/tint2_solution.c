/**
 * Распараллелить вычисление интеграла используя OpenMP.
 * Допустимо использование только прагм parallel, critical.
 * Николай Хохлов, k_h@inbox.ru, 2014.
 */

#include <stdio.h>
#include <math.h>
#include <omp.h>

#define A 2.0

double f(double x)
{
	return sqrt(4.0 - x * x);
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Usage: %s num_intervals.\n", argv[0]);
		return 1;
	}
	int i;
	int N = atoi(argv[1]);
	double h = A / N;
	double S = 0.0;
#pragma omp parallel private(i)
	{
		int tsize = omp_get_num_threads();
		int tnum = omp_get_thread_num();
		double S0 = 0.0;
		for (i = tnum; i < N; i += tsize) {
			S0 += h * (f(h * i) + f(h * (i + 1))) / 2.0;
		}
#pragma omp critical
		S += S0;
	}
	printf("%f\n", S);
	return 0;
}
