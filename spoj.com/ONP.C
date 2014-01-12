#include <stdio.h>
#include <string.h>
#include <ctype.h>

char result[400];
char *rpn = result;

const char *find_close_bracket(const char *expr, const char *end )
{
	int opened = 0;

	while ( expr < end ) {
		if ( '(' == *expr ) {
			opened++;
		} else if ( ')' == *expr && opened ) {
			opened--;
		} else if ( ')' == *expr && !opened ) {
			return expr;
		}
		expr++;
	}
	return expr;
}

void parse( const char *start, const char *end )
{
	char oper;
	if ( '(' == *start  ) {
		const char *bend = find_close_bracket(start+1, end);
		parse(start+1, bend);
		start = bend+1;
	} else {
		*rpn++ = *start++;
	}

	if ( start == end )
		return;

	oper = *start++;

	if ( '(' == *start  ) {
		const char *bend = find_close_bracket(start+1, end);
		parse(start+1, bend);
		start = bend+1;
	} else {
		*rpn++ = *start++;
	}

	*rpn++ = oper;
}

int main(void)
{
	int t;
	scanf("%d",&t);

	while ( t-- ) {
		char expr[400];
		scanf("%s", expr);

		rpn = result;
		parse(expr, expr+strlen(expr));

		result[rpn-result] = '\0';
		printf("%s\n", result);
	}

	return 0;
}
