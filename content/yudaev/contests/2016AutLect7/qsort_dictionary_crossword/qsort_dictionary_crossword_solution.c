#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define N 16

struct Word
{
	char str[N];
	char rev[N];
	int length;
};
void prn(struct Word * dict, int n)
{
	int i;
	return;
	printf("---------------------------\n");
	for(i=0; i<n; i++)
		printf("%d %s %s\n", dict[i].length, dict[i].str, dict[i].rev);
}
void read_word(char * str)
{
	int c;
	while((c=getchar())!=EOF)
		if (!isspace(c))
			break;
	while(isalpha(c)) {
		*str++ = c;
		c = getchar();
	}
	*str=0;
}
void revers(struct Word * w)
{
	char * src = w->str;
	char * rev = w->rev + w->length - 1;
	for(; *src; src++, rev--)
		*rev = *src;
	w->rev[w->length]='\0';
}
int cmp (const void * p1, const void * p2)
{
	const struct Word * w1 = p1;
	const struct Word * w2 = p2;
	if (w1->length == w2->length)
		return strcmp(w1->rev,w2->rev);
	return w1->length - w2->length;
}
int main()
{
	int n, i, length;
	struct Word * dict = NULL;
	scanf("%d", &n);
	dict = calloc(n, sizeof(struct Word));
	for(i=0; i<n; i++) {
		read_word(dict[i].str);
		dict[i].length = strlen(dict[i].str);
		revers(dict+i);
	}
	prn(dict, n);
	qsort(dict, n, sizeof(struct Word), cmp);
	prn(dict, n);
	for(i=0, length=0; i<n; i++) {
		if (length < dict[i].length) {
			length = dict[i].length;
			printf("%d\n", length);
		}
		printf("%s %s\n", dict[i].rev, dict[i].str);
	}
	free(dict);
	return 0;
}
