#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	while( T-- ) {
		int N, d=5, r=0;
		scanf("%d", &N);
		while ( d<=N ) {
			r += N/d;
			d *= 5;
		}
		printf("%d\n", r);
	}

	return 0;
}