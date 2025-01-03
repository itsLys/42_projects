#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <ft_printf.h>



void test_printf(const char *fmt, ...)
{
	va_list args1;
	va_list args2;

	va_start(args1 , fmt);
	va_start(args2 , fmt);

	static int w;
	printf("--------------------\n");
	printf("test case: %d\n", w++);
	printf("printf:		");
	int a = vprintf(fmt, args1);
	printf("\n");
	printf("ft_printf:	");
	fflush(stdout);
	int b = ft_printf(fmt, args2);
	printf("\n");
	assert(a == b);
}


int main()
{
	test_printf("Hello, %s! Your age is %d and your initial is %c.\n", "Bob", 30, 'B');
	test_printf("Pi is approximately %d.\n", 3);
	test_printf("Your name is %s and your lucky number is %d.\n", "Charlie", 7);
	test_printf("This is a simple string with no arguments.\n");
	test_printf("%d + %d = %d\n", 5, 3, 5 + 3);
	test_printf("Characters: %c, %c, %c\n", 'A', 'B', 'C');
	test_printf("Trying unsupported specifier: %f\n");
	test_printf("Name: %s, Age: %d, Grade: %c\n", "Daisy", 20, 'A');
	test_printf("Negative number: %d\n", -42);
	test_printf("Empty string: '%s'\n", "");
	test_printf("Zero value: %d\n", 0);
	test_printf("Special characters: %% (percent), \\ (backslash)\n");
	test_printf("Long string: %s\n", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer nec odio.");
	test_printf("Mixed: %d, %s, %x, %c\n", 25, "test", 255, 'Z');

}
