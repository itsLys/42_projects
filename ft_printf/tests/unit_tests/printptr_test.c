#include "test.h"

int main()
{


	void *ptr1 = (void *)0x12345678;
    void *ptr2 = (void *)0xABCDEF00;

	test_printf("|%p|\n", ptr1);             // Basic pointer
	test_printf("|%20p|\n", ptr1);            // Pointer with width
	test_printf("|%-20p|\n", ptr2);           // Left-justified pointer with width
	test_printf("|%p|\n", NULL);              // Null pointer
	test_printf("|%#p|\n", ptr1);             // '#' flag: prints pointer with `0x` prefix
	test_printf("|%.p|\n", ptr1);             // Precision: minimal (0 chars)
	test_printf("|%.10p|\n", ptr1);           // Precision with pointer (exact digits)
	test_printf("|%20.10p|\n", ptr1);         // Combined width and precision
	test_printf("|%-20.10p|\n", ptr2);        // Left-justified pointer with width and precision
	test_printf("|%.5p|\n", ptr1);            // Precision truncating pointer output

	// Edge Cases
	test_printf("|%p|\n", (void *)0);         // Null pointer
	test_printf("|%.0p|\n", (void *)0);       // Null pointer with precision 0 (empty output)
	test_printf("|%20.0p|\n", (void *)0);     // Null pointer with width and precision 0
	test_printf("|%-20.0p|\n", (void *)0);    // Left-justified null pointer with width and precision 0
	test_printf("|%.10p|\n", (void *)0);      // Precision with null pointer (should still show '0x0')
	test_printf("|%0p|\n", ptr1);             // '0' flag with pointer (no effect)

	// Misordered Flags, Width, Precision
	test_printf("|%0-.10p|\n", ptr1);         // Precision before '0' flag (undefined)
	test_printf("|%5-.p|\n", ptr2);           // Width, then flag '-', then precision (undefined)
	test_printf("|%.10-5p|\n", ptr1);         // Precision with width after '-' (undefined)
	test_printf("|%-0p|\n", ptr2);            // Conflicting flags: '-' and '0' with pointer (undefined)
	test_printf("|%0#-p|\n", ptr1);           // Conflicting flags '#' and '0' (undefined for %p)

	// Stress Testing
	test_printf("|%50p|\n", ptr1);            // Large width with pointer
	test_printf("|%.50p|\n", ptr2);            // Excessive precision (larger than pointer representation)
	test_printf("|%100p|\n", ptr1);            // Very large width with pointer
	test_printf("|%-100p|\n", ptr2);           // Left-justified very large width
	test_printf("|%100.50p|\n", ptr1);         // Combined large width and excessive precision
	test_printf("|%-100.50p|\n", ptr2);        // Left-justified combined width and excessive precision

	// Multiple Arguments
	test_printf("|%p%p%p|\n", ptr1, ptr2, NULL);  // Multiple pointer arguments
	test_printf("|%20p%-20p%.10p|\n", ptr1, ptr2, ptr1);  // Mixed width, flags, and precision
	test_printf("|%-20.5p%20.5p%10p|\n", ptr1, ptr2, NULL);  // Alignment and truncation
	test_printf("|%-10p%-10p%-10p%-10p%-10p|\n", ptr1, ptr2, NULL, ptr1, ptr2);  // Many pointers
	test_printf("|%5p%5p%5p|\n", ptr1, ptr2, NULL);  // Spaced pointers

	// Complex Misordered Flags
	test_printf("|%-0-5p|\n", ptr1);           // Conflicting flags and width (undefined)
	test_printf("|%--0p|\n", ptr2);            // Multiple conflicting flags (undefined)
	test_printf("|%-.5p|\n", ptr1);            // Precision before '-' (undefined)
	test_printf("|%.0-5p|\n", ptr1);           // Precision and width in wrong order (undefined)
	test_printf("|%5-.p|\n", ptr2);            // Width, then '-' and precision (undefined)

}
