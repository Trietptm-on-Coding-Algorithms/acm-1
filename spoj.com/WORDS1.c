#include <stdio.h>
#include <string.h>

#define ABC_LEN 26

struct abc {
	int used;
	int use_cnt;
	int conn[ABC_LEN];
};

int solve(struct abc *w)
{
	int i, j, k, x = -1, y = -1;

	for (k = 0; k < ABC_LEN; k++) {
		for (i = 0; i < ABC_LEN; i++) {
			for (j = 0; j < ABC_LEN; j++)
				w[i].conn[j] |= w[k].conn[i] & w[k].conn[j];
		}
	}

	for (i = 0; i < ABC_LEN; i++) {
		for (j = i + 1; j < ABC_LEN; j++) {
			if (w[i].used && w[j].used && !w[i].conn[j])
				return 0;
		}
	}
	
	for (i = 0; i < ABC_LEN; i++) {
		if (w[i].use_cnt == -1) {
			if (x != -1) return 0;
			x = i;
		}
		else if (w[i].use_cnt == 1) {
			if (y != -1) return 0;
			y = i;
		}
		else if (w[i].use_cnt != 0) {
			return 0;
		}
	}

	return (x == -1 && y == -1) || (x != -1 && y != -1);
}


int main()
{
	unsigned t = 0;
	scanf("%u", &t);

	while (t--) {
		unsigned n = 0;
		struct abc w[ABC_LEN];
		memset(w, 0, sizeof(w));
		scanf("%u", &n);

		while (n--) {
			unsigned fl, ll;
			unsigned char word[1001];
			scanf("%s", word);
			fl = word[0] - 'a';
			ll = word[strlen(word) - 1] - 'a';

			w[ll].conn[fl] = w[fl].conn[ll] = w[ll].used = w[fl].used = 1;
			w[fl].use_cnt++;
			w[ll].use_cnt--;
		}

		if (solve(w)) {
			puts("Ordering is possible.");
		}
		else {
			puts("The door cannot be opened.");
		}
	}

	return 0;
}
