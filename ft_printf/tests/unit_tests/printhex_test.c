#include "test.h"
#include <stdio.h>

int main() {
    unsigned int num1 = 0x1A3F;    // Hexadecimal number (uppercase: 1A3F, lowercase: 1a3f)
    unsigned int num2 = 0;         // Zero value
    unsigned int max_uint = 0xFFFFFFFF; // Maximum 32-bit unsigned integer

    // Basic Tests for `%x` and `%X`
    test_printf("|%x|\n", num1);             // Lowercase hex
    test_printf("|%X|\n", num1);             // Uppercase hex
    test_printf("|%#x|\n", num1);            // Alternate form with "0x"
    test_printf("|%#X|\n", num1);            // Alternate form with "0X"
    test_printf("|%10x|\n", num1);           // Right-justified with width
    test_printf("|%-10x|\n", num1);          // Left-justified with width
    test_printf("|%010x|\n", num1);          // Zero-padded width
    test_printf("|%.5x|\n", num1);           // Precision greater than number length
    test_printf("|%10.5x|\n", num1);         // Width and precision combined
    test_printf("|%-10.5x|\n", num1);        // Left-justified with width and precision

    // Edge Cases for `%x` and `%X`
    test_printf("|%x|\n", num2);             // Zero value (should print "0")
    test_printf("|%#x|\n", num2);            // Alternate form with zero value (should not print "0x")
    test_printf("|%.x|\n", num2);            // Precision with zero value (prints nothing)
    test_printf("|%.0x|\n", num2);           // Explicit precision zero with zero value (prints nothing)
    test_printf("|%x|\n", max_uint);         // Maximum unsigned int in hex (lowercase)
    test_printf("|%#x|\n", max_uint);        // Maximum unsigned int with "0x"
    test_printf("|%X|\n", max_uint);         // Maximum unsigned int in hex (uppercase)
    test_printf("|%#X|\n", max_uint);        // Maximum unsigned int with "0X"

    // Undefined Behavior Flags for `%x` and `%X`
    test_printf("|%+x|\n", num1);            // '+' flag (undefined for unsigned)
    test_printf("|% x|\n", num1);            // ' ' (space) flag (undefined for unsigned)
    test_printf("|%#0x|\n", num1);           // '#' and '0' combined (valid but may confuse implementation)
    test_printf("|%#-x|\n", num1);           // '#' and '-' combined (valid, should respect '-')
	printf("HHHHHHh\n");
    test_printf("|%#010x|\n", num1);         // '#' with zero-padded width
    test_printf("|%+#x|\n", num1);           // '#' and '+' combined (undefined)
    test_printf("|%-#x|\n", num1);           // '#' and '-' combined (valid, '-' takes precedence)
    test_printf("|%+-x|\n", num1);           // '+' and '-' combined (undefined)

    // Misordered Flags, Width, and Precision
    test_printf("|%0-.5x|\n", num1);         // Precision before '0' flag (undefined)
    test_printf("|%5-.x|\n", num1);          // Width, then '-' and precision (undefined)
    test_printf("|%#-010x|\n", num1);        // '#' with multiple conflicting flags
    test_printf("|%.5-5x|\n", num1);         // Precision with misordered width (undefined)
    test_printf("|%-.5x|\n", num1);          // Precision before '-' (undefined)

    // Stress Tests
    test_printf("|%50x|\n", num1);           // Large width with lowercase hex
    test_printf("|%50X|\n", num1);           // Large width with uppercase hex
    test_printf("|%.50x|\n", num1);          // Excessive precision with lowercase hex
    test_printf("|%.50X|\n", num1);          // Excessive precision with uppercase hex
    test_printf("|%100x|\n", num1);          // Very large width with lowercase hex
    test_printf("|%-100x|\n", num1);         // Left-justified with very large width
    test_printf("|%100.50x|\n", num1);       // Combined large width and precision
    test_printf("|%-100.50X|\n", num1);      // Left-justified large width and precision

    // Multiple Arguments
    test_printf("|%x %x %x|\n", num1, num2, max_uint); // Multiple hex values in one line
    test_printf("|%10x %-10X %.5x|\n", num1, num1, num1); // Mixed width, flags, and precision
    test_printf("|%-20.5x %20.5X %10x|\n", num1, num1, num1); // Alignment and truncation

    // Complex Misordered Flags
    test_printf("|%-0-5x|\n", num1);         // Conflicting flags and width (undefined)
    test_printf("|%--0x|\n", num1);          // Multiple conflicting flags (undefined)
    test_printf("|%+#0x|\n", num1);          // Undefined combination of flags
    test_printf("|%-+0x|\n", num1);          // Undefined combination of flags
    test_printf("|%#-0x|\n", num1);          // '#' with '-' and '0'

    return 0;
}
