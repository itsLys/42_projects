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

	printf("Default:	|%s|	|	Flag: '-5.3':	|%-5.3s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '-5.0':	|%-5.0s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '-5.':	|%-5.s|\n", str, str);
	printf("Default:	|%s|	|	Flag: '-5.10':	|%-5.10s|\n", str, str);

	printf("Default:	|%s|	|	Flag: '.3':	|%.3s|\n", NULL, NULL);
	printf("Default:	|%s|	|	Flag: '.0':	|%.0s|\n", NULL, NULL);
	printf("Default:	|%s|	|	Flag: '.':	|%.s|\n", NULL, NULL);
	printf("Default:	|%s|	|	Flag: '.10':	|%.10s|\n", NULL, NULL);

	printf("Default:	|%s|	|	Flag: '3':	|%3s|\n", NULL, NULL);
	printf("Default:	|%s|	|	Flag: '10':	|%10s|\n", NULL, NULL);

	printf("Default:	|%s|	|	Flag: '-3':	|%-3s|\n", NULL, NULL);
	printf("Default:	|%s|	|	Flag: '-0':	|%-0s|\n", NULL, NULL);
	printf("Default:	|%s|	|	Flag: '-':	|%-s|\n", NULL, NULL);
	printf("Default:	|%s|	|	Flag: '-10':	|%-10s|\n", NULL, NULL);

	printf("Default:	|%s|	|	Flag: '-.3':	|%-3s|\n", NULL, NULL);
	printf("Default:	|%s|	|	Flag: '-.0':	|%-0s|\n", NULL, NULL);
	printf("Default:	|%s|	|	Flag: '-.':	|%-s|\n", NULL, NULL);
	printf("Default:	|%s|	|	Flag: '-.10':	|%-10s|\n", NULL, NULL);

	printf("Default:	|%s|	|	Flag: '-5.3':	|%-5.3s|\n", NULL, NULL);
	printf("Default:	|%s|	|	Flag: '-5.0':	|%-5.0s|\n", NULL, NULL);
	printf("Default:	|%s|	|	Flag: '-5.':	|%-5.s|\n", NULL, NULL);
	printf("Default:	|%s|	|	Flag: '-5.10':	|%-5.10s|\n", NULL, NULL);
}
// calculate how many charachters are yu printing in total: field width
// calculate how many charachters from th string are you printing: precision
// determine if it is left or right adjusted: `-`
//
// if precision exists and < strlen("(null)")
// 	print_nothing;
