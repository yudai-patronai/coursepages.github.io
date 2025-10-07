#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Card {
    char suit;    // масть
    char rank;    // достоинство
};
void card_sort(struct Card card[], int n);

struct Card read_card()
{
	struct Card res; 
	int r, s, c;
	char * rank = "23456789TJQKA";
	char * suit = "cshd";
	while (1) {
		c = getchar();
		if (!isspace(c));
			break;
	}
	r = c;
	s = getchar();
	if (NULL==strchr(rank, r) || NULL==strchr(suit,s)) {
		printf("Wrong input data: r=%c s=%c\n", r, s);
		exit(1);
	}
	res.rank = (char)r;
	res.suit = (char)s;
	return res;
}
int main()
{
	int i, n;
	struct Card c[52];
	char s[100];
	fgets(s, 100, stdin);
	sscanf(s, "%d", &n);
	for(i=0; i<n; i++) {
		c[i] = read_card();
		//printf("%c%c\n", c[i].rank, c[i].suit);
	}	
	card_sort(c,n);
	
	for(i=0; i<n; i++)
		printf("%c%c", c[i].rank, c[i].suit);
	printf("\n");
	return 0;
}
