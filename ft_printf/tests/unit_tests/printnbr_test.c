#include "test.h"
#include <stdio.h>

int main()
{

	int num1 = 12345;
	int num2 = -67890;
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
	test_printf("|%.0d|\n", 0);                // Precision 0 with 0 value (prints nothing)
	test_printf("|%d|\n", 0);                  // Zero value
	test_printf("|%.d|\n", 0);                 // Precision with zero value (prints nothing)
	test_printf("|%5d|\n", 0);                 // Width with zero value
	test_printf("|%-5d|\n", 0);                // Left-justified width with zero value
	test_printf("|%010d|\n", 0);               // Zero-padded width with zero value
	test_printf("|%d|\n", INT_MAX);            // Maximum integer value
	test_printf("|%d|\n", INT_MIN);            // Minimum integer value
	test_printf("|%i|\n", INT_MAX);            // Maximum integer value with `%i`
	test_printf("|%i|\n", INT_MIN);            // Minimum integer value with `%i`
	test_printf("|%0-.5d|\n", num1);           // Precision before '0' flag (undefined)
	test_printf("|%5-.d|\n", num1);            // Width, then flag '-', then precision (undefined)
	test_printf("|%.5-5d|\n", num2);           // Precision with width after '-' (undefined)
	test_printf("|%-0d|\n", num1);             // Conflicting flags '-' and '0' (undefined)
	test_printf("|%0#d|\n", num1);             // '#' flag with %d (undefined)
	test_printf("|%50d|\n", num1);             // Large width with decimal
	test_printf("|%.50d|\n", num1);            // Excessive precision
	test_printf("|%100d|\n", num1);            // Very large width
	test_printf("|%-100d|\n", num2);           // Left-justified very large width
	test_printf("|%100.50d|\n", num1);         // Combined large width and excessive precision
	test_printf("|%d%d%d|\n", num1, num2, 0);  // Multiple decimal arguments
	test_printf("|%10d%-10d%.5d|\n", num1, num2, 42);  // Mixed width, flags, and precision
	test_printf("|%-20.5d%20.5d%10d|\n", num1, num2, 0);  // Alignment and truncation
	test_printf("|%-10d%-10d%-10d%-10d%-10d|\n", num1, num2, 0, INT_MAX, INT_MIN);  // Many integers
	test_printf("|%5d %5d %5d|\n", 1, 2, 3);   // Spaced integers
	test_printf("|%-0-5d|\n", num1);           // Conflicting flags and width (undefined)
	test_printf("|%--0d|\n", num2);            // Multiple conflicting flags (undefined)
	test_printf("|%-.5d|\n", num1);            // Precision before '-' (undefined)
	test_printf("|%.0-5d|\n", num1);           // Precision and width in wrong order (undefined)
	test_printf("|%5-.d|\n", num2);            // Width, then '-' and precision (undefined)
	test_printf("|%-100.50d|\n", num2);        // Left-justified large width and excessive precision
	test_printf("|%-10.5d|\n", num2);//////////// Left-justified with width and precision
	test_printf("|%-10.6d|\n", num2);//////////// Left-justified with width and precision
	test_printf("|%-10.7d|\n", num2);//////////// Left-justified with width and precision
	test_printf("|%04d|\n", 9);
	test_printf("|%03d|\n", 15);
	test_printf("|%04d|\n", 16);
	test_printf("|%05d|\n", 17);
	test_printf("|%04d|\n", -14);
	test_printf("|%05d|\n", -15);
	test_printf("|%06d|\n", -16);
	test_printf("|%011d|\n", LONG_MAX);
	test_printf("|%012d|\n", LONG_MIN);
	test_printf("|%013d|\n", UINT_MAX);
	test_printf("|%014d|\n", ULONG_MAX);
	test_printf("|%015d|\n", 9223372036854775807LL);
	test_printf("|%09d %010d %011d %012d %013d %014d %015d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, -42);
	test_printf("|%03i|\n", 1);
	test_printf("|%04i|\n", 9);
	test_printf("|%03i|\n", 15);
	test_printf("|%04i|\n", 16);
	test_printf("|%05i|\n", 17);
	test_printf("|%05i|\n", -15);
	test_printf("|%-4d|\n", -14);
	test_printf("|%-5d|\n", -15);
	test_printf("|%-6d|\n", -16);
	test_printf("|%-11d|\n", LONG_MAX);
	test_printf("|%-13d|\n", UINT_MAX);
	test_printf("|%-14d|\n", ULONG_MAX);
	test_printf("|%-15d|\n", 9223372036854775807LL);
	test_printf("|%-9d %-10d %-11d %-12d %-13d %-14d %-15d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	test_printf("|%-5i|\n", -15);
	test_printf("|%-6i|\n", -16);
	test_printf("|%04d|\n", 9);
	test_printf("|%03d|\n", 15);
	test_printf("|%04d|\n", 16);
	test_printf("|%05d|\n", 17);
	test_printf("|%04d|\n", -14);
	test_printf("|%05d|\n", -15);
	test_printf("|%06d|\n", -16);
	test_printf("|%011d|\n", LONG_MAX);
	test_printf("|%012d|\n", LONG_MIN);
	test_printf("|%013d|\n", UINT_MAX);
	test_printf("|%014d|\n", ULONG_MAX);
	test_printf("|%015d|\n", 9223372036854775807LL);
	test_printf("|%09d %010d %011d %012d %013d %014d %015d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	test_printf("|%03i|\n", 1);
	test_printf("|%04i|\n", 9);
	test_printf("|%03i|\n", 15);
	test_printf("|%04i|\n", 16);
	test_printf("|%05i|\n", 17);
	test_printf("|%05i|\n", -15);
	test_printf("|%.2d|\n", -1);
	test_printf("|%.2d|\n", 1);
	test_printf("|%.1d|\n", 9);
	test_printf("|%.2d|\n", 10);
	test_printf("|%.3d|\n", 11);
	test_printf("|%.4d|\n", 15);
	test_printf("|%.5d|\n", 16);
	test_printf("|%.6d|\n", 17);
	test_printf("|%.1d|\n", 99);
	test_printf("|%.2d|\n", -1);
	test_printf("|%.3d|\n", -11);
	test_printf("|%.4d|\n", -14);
	test_printf("|%.3d|\n", -99);
	test_printf("|%.4d|\n", -101);
	test_printf("|%.10d|\n", LONG_MAX);
	test_printf("|%.12d|\n", UINT_MAX);
	test_printf("|%.13d|\n", ULONG_MAX);
	test_printf("|%.14d|\n", 9223372036854775807LL);
	test_printf("|%.8d %.9d %.10d %.11d %.12d %.13d %.14d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	test_printf("|%.2i|\n", -1);
	test_printf("|%.3i|\n", -11);
	test_printf("|%.4i|\n", -14);
	test_printf("|%.3i|\n", -99);
	test_printf("|%.4i|\n", -101);
	test_printf("|%.10i|\n", LONG_MAX);
	test_printf("|%.12i|\n", UINT_MAX);
	test_printf("|%.13i|\n", ULONG_MAX);
	test_printf("|%.14i|\n", 9223372036854775807LL);
	test_printf("|% d|\n", 0);
	test_printf("|% d|\n", 1);
	test_printf("|% d|\n", 9);
	test_printf("|% d|\n", 10);
	test_printf("|% d|\n", 11);
	test_printf("|% d|\n", 15);
	test_printf("|% d|\n", 16);
	test_printf("|% d|\n", 17);
	test_printf("|% d|\n", 99);
	test_printf("|% d|\n", 100);
	test_printf("|% d|\n", 101);
	test_printf("|% d|\n", INT_MAX);
	test_printf("|% d|\n", LONG_MIN);
	test_printf("|% d % d % d % d % d % d % d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	test_printf("|%04d|\n", -14);
	test_printf("|%05d|\n", -15);
	test_printf("|%06d|\n", -16);
	test_printf("|%011d|\n", LONG_MAX);
	test_printf("|%013d|\n", UINT_MAX);
	test_printf("|%014d|\n", ULONG_MAX);
	test_printf("|%015d|\n", 9223372036854775807LL);
	test_printf("|%09d %010d %011d %012d %013d %014d %015d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	test_printf("|%05i|\n", -15);
	test_printf("|%06i|\n", -16);
	test_printf("|%01i|\n", -99);
	test_printf("|%012i|\n", LONG_MIN);
	test_printf("|%014i|\n", ULONG_MAX);
	test_printf("|%015i|\n", 9223372036854775807LL);
	test_printf("|%09i %010i %011i %012i %013i %014i %015i|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	test_printf("|%+d|\n", 0);
	test_printf("|%+d|\n", 9);
	test_printf("|%+d|\n", 10);
	test_printf("|%+d|\n", 11);
	test_printf("|%+d|\n", 15);
	test_printf("|%+d|\n", 16);
	test_printf("|%+d|\n", 17);
	test_printf("|%+d|\n", 99);
	test_printf("|%+d|\n", 100);
	test_printf("|%+d|\n", 101);
	test_printf("|%+d|\n", INT_MAX);
	test_printf("|%+d|\n", LONG_MIN);
	test_printf("|%+d %+d %+d %+d %+d %+d %+d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	test_printf("|%+i|\n", 0);
	test_printf("|%+i|\n", 1);
	test_printf("|%+i|\n", 9);
	test_printf("|%+i|\n", 10);
	test_printf("|%+i|\n", 11);
	test_printf("|%+i|\n", 15);
	test_printf("|%+48.27d|\n", -61180352);
	test_printf("|\\!/%+8d\\!/|\n", 0);
	test_printf("|42%+60d42|\n", 2034180068);
	test_printf("|\\!/%+11d\\!/|\n", 1884143904);
	test_printf("|\\!/% -12.8d\\!/|\n", 0);
	test_printf("|\\!/% -38.2d\\!/|\n", 463383700);
	test_printf("|\\!/%+-55.33d\\!/|\n", 0);
	test_printf("|^.^/%+-24.2d^.^/|\n", 0);
	test_printf("|\\!/%+-34.8d\\!/|\n", 0);
	test_printf("|% i|\n", 0);
	test_printf("|% i|\n", 1);
	test_printf("|% i|\n", 9);
	test_printf("|% i|\n", 10);
	test_printf("|% i|\n", 11);
	test_printf("|%8.5i|\n", 34);
	test_printf("|%10.5i|\n", -216);
	test_printf("|%8.5i|\n", 0);
	test_printf("|%8.3i|\n", 8375);
	test_printf("|%8.3i|\n", -8473);
	test_printf("|%-8.5i|\n", 34);
	test_printf("|%-10.5i|\n", -216);
	test_printf("|%-8.5i|\n", 0);
	test_printf("|%-8.3i|\n", -8473);
	test_printf("|%.0i|\n", 0);
	test_printf("|%.i|\n", 0);
	test_printf("|%5.0i|\n", 1);
	test_printf("|%5.i|\n", 0);
	test_printf("|%-5.0i|\n", 0);
	test_printf("|%-5.i|\n", 0);
	test_printf("|%08.5i|\n", 34);
	test_printf("|%010.5i|\n", -216);
	test_printf("|%08.5i|\n", 0);
	test_printf("|%08.3i|\n", 8375);
	test_printf("|%08.3i|\n", -8473);
}
