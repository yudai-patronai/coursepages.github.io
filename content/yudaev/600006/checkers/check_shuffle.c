#include <stdio.h>
#include <stdlib.h>

int compare_seq(int A1[], int A2[], int n) {
	int i;
	for (i = 0; i < n; i++)
		if (A1[i] != A2[i])
			return A1[i] - A2[i];
	return 0;
}

int cmp_ints(const void *p1, const void *p2) {
	return *(const int *)p1 - *(const int *)p2;
}

int check(FILE *input, FILE *output, FILE *correct) {
	int i, n;
	int A[1000], B[1000], C[1000];
	if (fscanf(input, "%i", &n) != 1)
		return 4;
	for (i = 0; i < n; i++)
		if (fscanf(input, "%i", &A[i]) != 1)
			return 4;
	if (fscanf(input, "%i", &i) == 1)
		return 4;
	for (i = 0; i < n; i++)
		if (fscanf(output, "%i", &B[i]) != 1)
			return 4;
	if (fscanf(output, "%i", &i) == 1)
		return 4;
	for (i = 0; i < n; i++)
		if (fscanf(correct, "%i", &C[i]) != 1)
			return 4;
	if (fscanf(correct, "%i", &i) == 1)
		return 4;
	if (n > 3)
		if (compare_seq(A, C, n) != 0 && compare_seq(A, B, n) == 0)
			return 5;
	qsort(A, n, sizeof(int), cmp_ints);
	qsort(B, n, sizeof(int), cmp_ints);
	qsort(C, n, sizeof(int), cmp_ints);
	if (compare_seq(A, C, n) != 0)
		return -1;
	if (compare_seq(A, B, n) != 0)
		return 5;
	return 0;
}

int main(int argc, char *argv[]) {
	int res = 0;
	FILE *input, *output, *correct;
	if (argc < 4)
		return -1;
	if ((input = fopen(argv[1], "rt")) != NULL) {
		if ((output = fopen(argv[2], "rt")) != NULL) {
			if ((correct = fopen(argv[3], "rt")) != NULL) {
				res = check(input, output, correct);
				fclose(correct);
			} else
				perror("fopen(correct)");
			fclose(output);
		} else
			perror("fopen(output)");
		fclose(input);
	} else
		perror("fopen(input)");
	return res;
}
