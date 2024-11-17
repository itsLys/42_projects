#include <stdio.h>

int main()
{
	//cspdiuxX%
	// printf("%[flags...][minimun_field_width][precision][length_modifier]conversion_specifier")
	int a = 123;
	int b = -456;
	int c = 0;
	char str[] = "Hello";
	char empty[] = "";
	
	printf("	 default:	|%d|		|	flag ` `:	|% d|\n", c, c);
	printf("Flags:\n");
	printf("`#`:Value should be converted to an \"alternate form\":\n");
	printf("`o` conversions: \n");
	printf("	 default:	|%o|		|	alternate:	|%#o|\n", a, a);
	printf("	 default:	|%o|		|	alternate:	|%#o|\n", c, c);
	printf("\n");
	printf("`x` conversions: \n");
	printf("	 default:	|%x|		|	alternate:	|%#x|\n", a, a);
	printf("	 default:	|%x|		|	alternate:	|%#x|\n", c, c);
	printf("\n");
	printf("`X` conversions: \n");
	printf("	 default:	|%X|		|	alternate:	|%#X|\n", a, a);
	printf("	 default:	|%X|		|	alternate:	|%#X|\n", c, c);
	printf("\n");
	// Undefined for other conversions
	//
	printf("`0`:Value should be zero padded\n");
	printf("	 default:	|%9o|		|	flag `0`:	|%09o|\n", a, a);
	printf("	 default:	|%9x|		|	flag `0`:	|%09x|\n", a, a);
	printf("	 default:	|%9d|		|	flag `0`:	|%09d|\n", b, b);
	printf("	 default:	|%9i|		|	flag `0`:	|%09i|\n", c, c);
	printf("\n");
	// if `0` and `-` flags both appear
	// 	ignore `0`
	printf("	 default:	|%9d|		|	flag `0`,`-`:	|%-09d|\n", b, b);
	printf("	 default:	|%9d|		|	flag `0`,`-`:	|%0-9d|\n", b, b);
	printf("\n");
	// if precision is given with a numeric conversion
	// 	ignore `0`
	printf("\n");
	printf("	 default:	|%9d|		|	flag `0`:	|%0.9d|\n", a, a);
	printf("	 default:	|%9d|		|	flag `0`:	|%0.9d|\n", b, b);
	// undefined behavior for other conversions
	printf("\n");
	printf("`-`:Value should be left adjusted on the field boundary:\n");
	printf("	 default:	|%9o|		|	flag `-`:	|%-9o|\n", a, a);
	printf("	 default:	|%9x|		|	flag `-`:	|%-9x|\n", a, a);
	printf("	 default:	|%9d|		|	flag `-`:	|%-9d|\n", b, b);
	printf("	 default:	|%9i|		|	flag `-`:	|%-9i|\n", c, c);
	printf("\n");
	// if `-` and `0` both appear
	// 	override `0`
	printf("	 default:	|%9d|		|	flag `-`,`0`:	|%-09d|\n", b, b);
	printf("\n");
	printf("` `(space):A blank should be left before a positive number(or empty string)\n");
	printf("	 default:	|%d|		|	flag ` `:	|% d|\n", a, a);
	printf("	 default:	|%d|		|	flag ` `:	|% d|\n", b, b);
	printf("	 default:	|%d|		|	flag ` `:	|% d|\n", c, c);
	printf("\n");
	printf("`+`: Forces a sign for signed conversions\n");
	printf("	 default:	|%d|		|	flag `+`:	|%+d|\n", a, a);
	printf("	 default:	|%d|		|	flag `+`:	|%+d|\n", b, b);
	printf("	 default:	|%d|		|	flag `+`:	|%+d|\n", c, c);
	// if there is space and `+`
	// 	ignore ` `
	printf("	 default:	|%d|		|	flag [`+`,` `]:	|%+ d|\n", a, a);
	printf("	 default:	|%d|		|	flag [` `,`+`]:	|% +d|\n", a, a);


}
