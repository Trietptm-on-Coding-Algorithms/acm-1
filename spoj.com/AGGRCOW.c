#include <stdio.h>
#include <stdlib.h>

unsigned N, C, stalls[100000];

int place(unsigned d)
{
	unsigned i, cows = 1, pos = stalls[0];

	for (i = 1; i<N; i++) {
		if (stalls[i] - pos >= d) {
			cows++;

			if (cows == C)
				return 1;
			pos = stalls[i];
		}
	}

	return 0;
}

unsigned solve()
{
	unsigned start = 0, end = stalls[N - 1];
	while (start < end) {
		unsigned mid = (start + end) / 2;
		if (place(mid))
			start = mid + 1;
		else
			end = mid;
	}
	return start - 1;
}

int uint_cmp(const void *a, const void *b)
{
	if (*(unsigned*)a <  *(unsigned*)b) return -1;
	if (*(unsigned*)a == *(unsigned*)b) return 0;
	if (*(unsigned*)a >  *(unsigned*)b) return 1;
}

int main()
{
	unsigned i, t;
	scanf("%u", &t);

	while (t--) {
		scanf("%u %u", &N, &C);

		for (i = 0; i < N; i++) {
			scanf("%u", &stalls[i]);
		}

		qsort(stalls, N, sizeof(stalls[0]), uint_cmp);
		printf("%u\n", solve());
	}

	return 0;
}