#include "ft_printf.h"
#include <stdio.h>
#include <assert.h>
void test_check_valid(char *fmt, int exp)
{
	int is_valid = check_valid(fmt);
	printf("fmt:	%s", fmt);
	printf("Format is: %s", is_valid ? "TRUE" : "FALSE");
	assert((exp == is_valid) && "Test Failed" );
}


int main()
{
	// Valid format strings
	test_check_valid("%d", 1);                 // Simple format
	test_check_valid("%-10d", 1);              // Left-justified with width
	test_check_valid("%+10d", 1);              // Sign flag with width
	test_check_valid("%010d", 1);              // Zero-padded with width
	test_check_valid("% 10d", 1);              // Space flag with width
	test_check_valid("%#.5x", 1);              // Alternate form with precision
	test_check_valid("%10.5d", 1);             // Width and precision
	test_check_valid("%-#10.5x", 1);           // Combination of flags, width, and precision
	test_check_valid("%*.*f", 1);              // Dynamic width and precision
	test_check_valid("%0*d", 1);               // Dynamic width with zero-padding
	test_check_valid("%.*s", 1);               // Dynamic precision
	test_check_valid("%.0f", 1);               // Precision of 0
	test_check_valid("%10c", 1);               // Width with character
	test_check_valid("%-#10.5o", 1);           // Alternate form, width, precision for octal
	test_check_valid("%10.3e", 1);             // Width and precision for scientific notation

	// Invalid format strings
	test_check_valid("%d10", 0);              // Incorrect placement of width
	test_check_valid("%.-10d", 0);            // Invalid flag usage
	test_check_valid("%10..5d", 0);           // Extra period in precision
	test_check_valid("%#0-10.5x", 0);         // Conflicting flags: 0 and -
	test_check_valid("%10.5.2d", 0);          // Multiple precision specifiers
	test_check_valid("%-*10d", 0);            // Multiple conflicting widths
	test_check_valid("%#.x", 0);              // Alternate form without conversion specifier
	test_check_valid("%10.0.5f", 0);          // Multiple precision
	test_check_valid("%+-.5d", 0);            // Conflicting flags
	test_check_valid("%*.*.d", 0);            // Extra dynamic precision specifier

	// Edge cases
	test_check_valid("%", 0);                 // Missing conversion specifier
	test_check_valid("%.", 0);                // Just a period
	test_check_valid("%*", 0);                // Missing dynamic value
	test_check_valid("%*10d", 0);             // Dynamic width with conflicting static width
	test_check_valid("%0+10.5d", 1);           // Valid combination of 0 and +
	test_check_valid("%+010d", 0);            // Conflicting flags: + and 0 with -
	test_check_valid("%- 10d", 1);             // Valid combination of - and space

	// Specialized formats
	test_check_valid("%%", 1);                 // Escaped percentage
	test_check_valid("%10%", 1);               // Width with escaped percentage
	test_check_valid("%.%", 0);               // Precision without a valid conversion specifier
	test_check_valid("%#%", 0);               // Alternate form with escaped percentage
	test_check_valid("%-10%", 1);              // Left-justified escaped percentage
}
