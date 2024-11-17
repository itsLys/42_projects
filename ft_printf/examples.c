#include <stdio.h>

int main()
{
	//cspdiuxX%
	// printf("%[flags...][minimun_field_width][precision][length_modifier]conversion_specifier")
	int a = 123;
	int b = -456;
	int c = 0;
	int d = 123456789;
	char str[] = "Hello";
	char empty[] = "";
	
	printf("	 default:	|%d|		|	flag ` `:	|% d|\n", c, c);
	printf("Flags:\n");
	printf("`#`:Value should be converted to an \"alternate form\":\n");
	printf("`o` conversions: \n");
	printf("	 default:	|%o|	|	flag `#`:	|%#o|\n", a, a);
	printf("	 default:	|%o|		|	flag `#`:	|%#o|\n", c, c);
	printf("\n");
	printf("`x` conversions: \n");
	printf("	 default:	|%x|	|	flag `#`:	|%#x|\n", a, a);
	printf("	 default:	|%x|		|	flag `#`:	|%#x|\n", c, c);
	printf("\n");
	printf("`X` conversions: \n");
	printf("	 default:	|%X|	|	flag `#`:	|%#X|\n", a, a);
	printf("	 default:	|%X|		|	flag `#`:	|%#X|\n", c, c);
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
	printf("	 default:	|%d|			|	flag ` `:	|% d|\n", c, c);
	printf("\n");
	printf("`+`: Forces a sign for signed conversions\n");
	printf("	 default:	|%d|		|	flag `+`:	|%+d|\n", a, a);
	printf("	 default:	|%d|		|	flag `+`:	|%+d|\n", b, b);
	printf("	 default:	|%d|			|	flag `+`:	|%+d|\n", c, c);
	// if there is space and `+`
	// 	ignore ` `
	printf("	 default:	|%d|		|	flag [`+`,` `]:	|%+ d|\n", a, a);
	printf("	 default:	|%d|		|	flag [` `,`+`]:	|% +d|\n", a, a);

	printf("\n");
	printf("Field Width: An optional decimal digit string, (with nonzero first digit)\n");
	printf("specifying a minimum field width\n");
	printf("	 default:	|%d|		|	wiedth 8:	|%8d|\n", a, a);
	printf("	 default:	|%d|	|	wiedth 8:	|%8d|\n", d, d);
	// if field with < 0
	// 	align left
	printf("	 default:	|%d|		|	wiedth -8:	|%-8d|\n", b, b);
	printf("\n");
	printf("Precision: An optional `.` followed by an optional decimal digit string\n");
	printf("	 default:	|%d|		|	precision `.8`:		|%.8d|\n", a, a);
	printf("	 default:	|%d|		|	precision `.[0]`:	|%.0d|\n", b, b);
	printf("	 default:	|%s|		|	precision `.3`:		|%.3s|\n", str, str);
	printf("	 default:	|%x|		|	precision `.8`:		|%.8x|\n", a, a);
	printf("	 default:	|%o|		|	precision `.8`:		|%.8o|\n", a, a);
	printf("	 default:	|%x|		|	precision `#.8`:	|%#.8x|\n", a, a);
	printf("	 default:	|%o|		|	precision `#.8`:	|%#.8o|\n", a, a);
	// if precision < 0
	// 	ignore precision
	printf("	 default:	|%d|		|	precision `.-8`:	|%.*d|\n", a, -8,  a); 
	// if 0 is the value and presicion == 0, the output is empty
	printf("	 default:	|%d|			|	precision `.0`:		|%.0d|\n", c, c);
	// negative presicion can only be done using an argument
	printf("\n");
	printf("Length modifiers:\n");
}
