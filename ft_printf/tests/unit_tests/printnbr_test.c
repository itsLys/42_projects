#include "test.h"
#include <stdio.h>

int main()
{

 int num1 = 12345;
    int num2 = -67890;

    // Basic Tests
    test_printf("|%d|\n", num1);               // Basic decimal
    test_printf("|%i|\n", num2);               // Basic integer
    test_printf("|%+d|\n", num1);              // '+' flag for positive number
    test_printf("|% d|\n", num1);              // ' ' (space) flag for positive number
    test_printf("|%-d|\n", num1);              // Left-justified with '-'
    test_printf("|%05d|\n", num1);             // Zero-padded with width
    test_printf("|%5d|\n", num1);              // Right-justified with width
    test_printf("|%-5d|\n", num2);             // Left-justified with width
    test_printf("|%.5d|\n", num1);             // Precision greater than number length
    test_printf("|%10.5d|\n", num1);           // Combined width and precision
    test_printf("|%-10.5d|\n", num2);          // Left-justified with width and precision
    test_printf("|%.0d|\n", 0);                // Precision 0 with 0 value (prints nothing)

    // Edge Cases
    test_printf("|%d|\n", 0);                  // Zero value
    test_printf("|%.d|\n", 0);                 // Precision with zero value (prints nothing)
    test_printf("|%5d|\n", 0);                 // Width with zero value
    test_printf("|%-5d|\n", 0);                // Left-justified width with zero value
    test_printf("|%010d|\n", 0);               // Zero-padded width with zero value
    test_printf("|%d|\n", INT_MAX);            // Maximum integer value
    test_printf("|%d|\n", INT_MIN);            // Minimum integer value
    test_printf("|%i|\n", INT_MAX);            // Maximum integer value with `%i`
    test_printf("|%i|\n", INT_MIN);            // Minimum integer value with `%i`

    // Misordered Flags, Width, Precision
    test_printf("|%0-.5d|\n", num1);           // Precision before '0' flag (undefined)
    test_printf("|%5-.d|\n", num1);            // Width, then flag '-', then precision (undefined)
    test_printf("|%.5-5d|\n", num2);           // Precision with width after '-' (undefined)
    test_printf("|%-0d|\n", num1);             // Conflicting flags '-' and '0' (undefined)
    test_printf("|%0#d|\n", num1);             // '#' flag with %d (undefined)

    // Stress Testing
    test_printf("|%50d|\n", num1);             // Large width with decimal
    test_printf("|%.50d|\n", num1);            // Excessive precision
    test_printf("|%100d|\n", num1);            // Very large width
    test_printf("|%-100d|\n", num2);           // Left-justified very large width
    test_printf("|%100.50d|\n", num1);         // Combined large width and excessive precision
    test_printf("|%-100.50d|\n", num2);        // Left-justified large width and excessive precision

    // Multiple Arguments
    test_printf("|%d%d%d|\n", num1, num2, 0);  // Multiple decimal arguments
    test_printf("|%10d%-10d%.5d|\n", num1, num2, 42);  // Mixed width, flags, and precision
    test_printf("|%-20.5d%20.5d%10d|\n", num1, num2, 0);  // Alignment and truncation
    test_printf("|%-10d%-10d%-10d%-10d%-10d|\n", num1, num2, 0, INT_MAX, INT_MIN);  // Many integers
    test_printf("|%5d %5d %5d|\n", 1, 2, 3);   // Spaced integers

    // Complex Misordered Flags
    test_printf("|%-0-5d|\n", num1);           // Conflicting flags and width (undefined)
    test_printf("|%--0d|\n", num2);            // Multiple conflicting flags (undefined)
    test_printf("|%-.5d|\n", num1);            // Precision before '-' (undefined)
    test_printf("|%.0-5d|\n", num1);           // Precision and width in wrong order (undefined)
    test_printf("|%5-.d|\n", num2);            // Width, then '-' and precision (undefined)
}
