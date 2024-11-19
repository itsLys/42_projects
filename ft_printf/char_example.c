
#include <stdio.h>

int main()
{
	char c = 'H';
	printf("	 default:	|%c|		|	flag `0`:	|%0c|\n", c, c);
	printf("	 default:	|%c|		|	flag `-`:	|%-c|\n", c, c);
	printf("	 default:	|%c|		|	flag `#`:	|%#c|\n", c, c);
	printf("	 default:	|%c|		|	flag `+`:	|%+c|\n", c, c);
	printf("	 default:	|%c|		|	flag ` `:	|% c|\n", c, c);

	printf("	 default:	|%c|		|	flag `0-`:	|%0-c|\n", c, c);
	printf("	 default:	|%c|		|	flag `-#`:	|%-#c|\n", c, c);
	printf("	 default:	|%c|		|	flag `#+`:	|%#+c|\n", c, c);
	printf("	 default:	|%c|		|	flag `+ `:	|%+ c|\n", c, c);
	printf("	 default:	|%c|		|	flag ` 0`:	|% 0c|\n", c, c);

	printf("	 default:	|%c|		|	width `1`:	|%0c|\n", c, c);
	printf("	 default:	|%c|		|	width `3`:	|%3c|\n", c, c);
	printf("	 default:	|%c|		|	flag `-`  width '3':	|%-3c|\n", c, c);
	printf("	 default:	|%c|		|	flag `+ ` width '3':	|%+ 3c|\n", c, c);
	printf("	 default:	|%c|		|	flag `+0` width '3':	|%+ 03c|\n", c, c);
	printf("	 default:	|%c|		|	flag ` 0+-` width '3':	|% 0+-3c|\n", c, c);
}
