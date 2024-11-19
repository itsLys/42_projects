#include <stdio.h>

int main(void)
{
	char str[] = "Hello World;$%^";
	printf("String examples: \n");
	printf("Default:	|%s|	|	Flag: '.3':	|%.3s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '.0':	|%.0s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '.':	|%.0s|\n", str, str);
}
