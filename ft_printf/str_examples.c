#include <stdio.h>

int main(void)
{
	char str[] = "Hello World;$%^";
	printf("String examples: \n");
	printf("Default:	|%s|	|	Flag: '.3':	|%.3s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '.0':	|%.0s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '.':	|%.s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '.10':	|%.10s|\n", str, str);

	printf("Default:	|%s|	|	Flag: '3':	|%3s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '10':	|%10s|\n", str, str);

	printf("Default:	|%s|	|	Flag: '-3':	|%-3s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '-0':	|%-0s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '-':	|%-s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '-10':	|%-10s|\n", str, str);

	printf("Default:	|%s|	|	Flag: '-.3':	|%-3s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '-.0':	|%-0s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '-.':	|%-s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '-.10':	|%-10s|\n", str, str);

	printf("Default:	|%s|	|	Flag: '-5.3':	|%-3s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '-5.0':	|%-0s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '-5.':	|%-s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '-5.10':	|%-10s|\n", str, str);
}
