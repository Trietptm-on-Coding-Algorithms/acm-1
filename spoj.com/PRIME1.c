#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t;
	scanf("%d", &t);
	while ( t-- ) {
		int n, m, i, p;
		int *primes;

		scanf("%d%d", &n, &m);

		primes = calloc(m-n+1, sizeof(*primes));

		for ( p=2; p*p<=m; ++p )
		{
			int j, fp = n / p * p;

			for ( j=fp; j<=m; j+=p ) {
				if(j != p && j >= n)
					primes[j - n] = 1;
			}
		}

		for ( i=0; i<m-n+1; ++i ) {
			if ( primes[i] == 0 && (n+i != 1) )
				printf("%d\n",n+i);
		}

		if ( t )
			printf("\n");

		free(primes);
	}

	return 0;
}