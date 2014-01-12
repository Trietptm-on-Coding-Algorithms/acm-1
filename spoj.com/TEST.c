#include <stdio.h>

int main()
{
	int n = 0;
	for(;;) {
		scanf("%d", &n);
		if ( 42 == n )
			return 0;
		else
			printf("%d\n", n);
	}
}