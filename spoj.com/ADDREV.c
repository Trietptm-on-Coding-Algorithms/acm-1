#include <stdio.h>

typedef unsigned long long int unum;

unum nrev( unum n )
{
	unum r=0;
	while ( n ) {
		r = r*10 + n%10;
		n = n/10;
	}
	return r;
}

int main()
{
	int N;
	scanf("%d", &N);
	while ( N-- ) {
		unum a,b,c;
		scanf("%llu%llu", &a, &b);
		c = nrev(a) + nrev(b);
		printf("%llu\n", nrev(c));
	}
	return 0;
}