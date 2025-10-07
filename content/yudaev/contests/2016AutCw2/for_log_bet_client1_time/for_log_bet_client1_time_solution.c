#include <stdio.h>

#define TIMEBIG 2000000000ULL
#define CLIENTBIG 1000
#define IDBIG   100000000ULL


typedef unsigned long long Time;
typedef unsigned long long ID;
typedef struct _Coupon {
    Time            time;
    unsigned int    client_id;
    ID              id;
} Coupon;

void limitCoupon(Coupon * a); // check task limitation decribed in statement

Coupon  readCoupon();
void    printCoupon( Coupon a);

void limitCoupon(Coupon * a)
{
    if (a->time > TIMEBIG)
        printf("Limit overflow: timestamp %llu (limit %llu)\n", a->time, TIMEBIG);
    if (a->client_id > CLIENTBIG)
        printf("Limit overflow: timestamp %u (limit %u)\n", a->client_id, CLIENTBIG);
    if (a->id < IDBIG)
        printf("Limit overflow: timestamp %llu (limit %llu)\n", a->id, IDBIG);
}
Coupon readCoupon()
{
    Coupon res;
    static int line = 0;    // scanned coupon counter
    if (3!=scanf("%llu%u%llu", &res.time, &res.client_id, &res.id)) 
        printf("Coupon %d expected, but not read\n", line);
    line ++;
    return res;
}

void printCoupon( Coupon a)
{
    printf("%llu %u %llu\n", a.time, a.client_id, a.id);
}

int main()
{
    int k, n, i;
    scanf("%d", &k);
    scanf("%d", &n);
	Coupon a1 = {0, 0, 0};
	Coupon a2 = {0, 0, 0};
	Coupon b;
    for (i=0; i<n; i++) {
        b = readCoupon();
        if (b.client_id != k) 
            continue;
            
        if (a1.time == 0)
            a1 = b;
        else;
            a2 = b;
    }

    if (a2.time == 0)
        printf("0\n");
    else 
        printf("%llu\n", a2.time - a1.time);
	return 0;
}	