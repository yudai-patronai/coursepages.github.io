#include <stdio.h>
#define SICKLE1 29
#define GALLEON 17

#define KNUTLIMIT 10000
#define SICKLELIMIT 10000
#define GALLEONLIMIT 5000

typedef unsigned int uint;
typedef struct _Money {
    int g;
    int s;
    int k;
    unsigned long total;
} Money;

void limitMoney(Money * a); // check task limitation decribed in statement

long total(int g, int s, int k);
Money readMoney();
Money normal( Money a);
void normalize( Money *a);
void printMoney( Money a);
Money addMoney(Money a, Money b);
Money subMoney(Money a, Money b);

void limitMoney(Money * a)
{
    if (a->k > KNUTLIMIT || a->k < 0)
        printf("Limit overflow or negative: knuts %d (limit %d)\n", a->k, KNUTLIMIT);
    if (a->s > SICKLELIMIT || a->s < 0)
        printf("Limit overflow or negative: knuts %d (limit %d)\n", a->k, SICKLELIMIT);
    if (a->g > GALLEONLIMIT ||  a->g < 0)
        printf("Limit overflow or negative: knuts %d (limit %d)\n", a->k, GALLEONLIMIT);
}
Money readMoney()
{
    Money res;
    scanf("%u%u%u", &res.g, &res.s, &res.k);
    res.total = total(res.g, res.s, res.k);
    return res;
}
long total(int g, int s, int k)
{
    long res;
    res =  g * GALLEON + s;     // to sickles
    res =  res * SICKLE1 + k;   // to knuts
    return res;
}
Money normal( Money a)
{
    Money res = a;
    normalize(&res);
    return res;
}
void normalize( Money *a)
{
    long t = a->total;
    a->k = t % SICKLE1;
    t /= SICKLE1;
    a->s = t % GALLEON;
    t /= GALLEON;
    a->g = t;
}
void printMoney( Money a)
{
    printf("%u %u %u\n", a.g, a.s, a.k);
}
Money addMoney(Money a, Money b)
{
    Money res;
    res.total = a.total + b.total;
    normalize(&res);
    return res;
}
Money subMoney(Money a, Money b)
{
    Money res;
    res.total = a.total - b.total;
    normalize(&res);
    return res;
}
int main()
{
	Money a = readMoney();
	Money b = readMoney();
    Money res = subMoney(a, b);
    printMoney(res);
    
    limitMoney(&a);
    limitMoney(&b);
    limitMoney(&res);
	
	return 0;
}	