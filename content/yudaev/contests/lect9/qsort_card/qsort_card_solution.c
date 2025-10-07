int cmp_card(const void * p1, const void * p2)
{
	static char * rank = "23456789TJQKA";
	static char * suit = "cshd";
	
	struct Card * c1 = (struct Card *) p1;
	struct Card * c2 = (struct Card *) p2;
	
	int res = strchr(rank, c1->rank) - strchr(rank, c2->rank);
	if (res==0)
		return strchr(suit, c1->suit) - strchr(suit, c2->suit);
	return res;
}


void card_sort(struct Card card[], int n)
{
	qsort(card, n, sizeof(struct Card), cmp_card); 
}
