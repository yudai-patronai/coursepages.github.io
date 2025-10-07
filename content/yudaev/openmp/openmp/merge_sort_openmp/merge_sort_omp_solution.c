/*
 * Николай Игоревич Хохлов, k_h@inbox.ru, 2014.
 * Реализация алгоритма сортировки слиянием.
 * Распараллелить используя OpenMP и алгоритм гиперкуб.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <omp.h>

void merge(int *a, int *b, int *c, int na, int nb);
void merge_sort(int *a, int na);
void print(int *a, int na);
int check_sort(int *a, int n);
double timer();

int pow2(int i)
{
	return 1 << i;
}

int main (int argc, char *argv[])
{
	int i, n, *a;
	double t;
	if (argc < 2) {
		printf("Usage: %s num_elements.\n", argv[0]);
		return 1;
	}
	n = atoi(argv[1]);
	a = (int*)malloc(sizeof(int) * n);
	srand(time(NULL));

	for (i = 0; i < n; i++) a[i] = rand() % 1000;

	if (n < 101) print(a, n);

	t = timer();

	int size, rank, mask, partner;
	int *st, *fn;
	#pragma omp parallel private(rank, i, mask, partner)
	{
		#pragma omp single
		{
			size = omp_get_num_threads();
			st = (int*)malloc(sizeof(int) * size);
			fn = (int*)malloc(sizeof(int) * size);
		}
		rank = omp_get_thread_num();
		
		/* Делим между процессами. */
		int pertask = n / size;
		st[rank] = rank * pertask;
		fn[rank] = st[rank] + pertask;
		if (rank == size - 1) fn[rank] = n;
		
		/* Каждый сортирует свою часть. */
		merge_sort(a + st[rank], fn[rank] - st[rank]);

		/* Сбор данных у мастера. */
		mask = 0;
		for (i = 0; i < ceil(log2(size)); i++) {
			#pragma omp barrier
			/* Берем процессы, чей i-й бит 0. */
			if ((rank & mask) == 0) {
				/* Номер партнера, с которым будем взаимодействовать. */
				partner = rank ^ pow2(i);
				/* Проверка на то, что мы не вышли за нумерацию процессов. */
				if (partner < size) {
					if ((rank & pow2(i)) == 0) {
						int na = fn[rank] - st[rank];
						int nb = fn[partner] - st[partner];
						int *c = (int*)malloc(sizeof(int) * (na + nb));
						merge(a + st[rank], a + st[partner], c, na, nb);
						memcpy(a + st[rank], c, sizeof(int) * (na + nb));
						fn[rank] = fn[partner];
						free(c);
					}
				}
			}
			/* Выставить i-й бит маски в 1. */
			mask = mask ^ pow2(i);
		}
	}

	
	t = timer() - t;

	if (n < 101) print(a, n);
	printf("Time: %f sec, sorted: %d\n", t, check_sort(a, n));
	free(a);
	free(st);
	free(fn);
	return 0;
}

double timer()
{
	struct timeval ts;
	gettimeofday(&ts, NULL);
	return (double)ts.tv_sec + 1e-6 * (double)ts.tv_usec;
}

int check_sort(int *a, int n)
{
	int i;
	for (i = 0; i < n - 1; i++) {
		if (a[i] > a[i+1]) {
			return 0;
		}
	}
	return 1;
}

void print(int *a, int na)
{
	int i;
	for (i = 0; i < na; i++) printf("%d ", a[i]);
	printf("\n");
}

/*
 * Процедура слияния массивов a и b в массив c.
 */
void merge(int *a, int *b, int *c, int na, int nb)
{
	int i = 0, j = 0;
	while (i < na && j < nb) {
		if (a[i] <= b[j]) {
			c[i + j] = a[i];
			i++;
		} else {
			c[i + j] = b[j];
			j++;
		}
	}
	if (i < na) {
		memcpy(c + i + j, a + i, (na - i) * sizeof(int));
	} else {
		memcpy(c + i + j, b + j, (nb - j) * sizeof(int));
	}
}

/*
 * Процедура сортировки слиянием.
 */
void merge_sort(int *a, int na)
{
	if(na < 2) return;
	if(na == 2) {
		if(a[0] > a[1]) { int t = a[0]; a[0]=a[1]; a[1]=t; }
		return;
	}
	merge_sort(a, na / 2);
	merge_sort(a + na / 2, na - na / 2);

	int *b = (int*)malloc(sizeof(int) * na);
	
	merge(a, a + na / 2, b, na / 2, na - na / 2);
	
	memcpy(a, b, sizeof(int) * na);
	
	free(b);
}
