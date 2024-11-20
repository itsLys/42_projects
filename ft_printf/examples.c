#include <limits.h>
#include <stdio.h>

int main()
{
	//what?
	//cspdiuxX%
	//`-0.` `# +`
	// printf("%[flags...][minimun_field_width][precision][length_modifier]conversion_specifier")
	int a = 123;
	int b = -456;
	int c = 0;
	int e = 'B';
	unsigned u = 2147483647;
	void *p = "Hello";
	char *empty = "";
	char *null = NULL;

	printf("|%p|\n", p);
	printf("|% p|\n", p);
	printf("|% +p|\n", null);
	printf("|% p|\n", null);
	printf("|% 30p|\n", null);
	printf("|%20p|\n", p);
	printf("|%-20p|\n", p);
	printf("|%+20p|\n", p);
	printf("|%020p|\n", p);
	printf("|%0+20p|\n", p);
	printf("|%0+20.20p|\n", p);
	printf("|%030.20p|\n", p);
	printf("|%0+40.20p|\n", p);
}
// char accepts only width and left alignment coupled with width
//+0x00000000000000000055faaa324004
//
//                 +0x00000000564a80606004|
