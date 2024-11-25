#include "test.h"

int main()
{

	test_printf("|%s|\n", "Hello");
	test_printf("|%-s|\n", "World");
	test_printf("|%+s|\n", "Test");                   // Undefined: '+' flag with %s
	test_printf("|% s|\n", "Space");                 // Space flag (no effect for %s)
	test_printf("|%#s|\n", "Hash");                  // Undefined: '#' flag with %s
	test_printf("|%0s|\n", "Zero");                  // Undefined: '0' flag with %s
	test_printf("|%.s|\n", "Precision");             // Precision 0 (empty output)
	test_printf("|%20s|\n", "Width Test");           // Right-justified with width
	test_printf("|%-20s|\n", "Left Width");          // Left-justified with width
	test_printf("|%.5s|\n", "Truncated String");     // Precision truncating string
	test_printf("|%20.5s|\n", "Width and Precision"); // Combined width and precision

	// Edge Cases
	test_printf("|%s|\n", NULL);                     // Null pointer
	test_printf("|%.0s|\n", "Empty Precision");      // Empty precision (no characters)
	test_printf("|%20.0s|\n", "Empty Precision");    // Width with empty precision
	test_printf("|%-20.0s|\n", "Empty Precision");   // Left-justified empty precision
	test_printf("|%.5s|\n", NULL);                   // Precision with null pointer
	test_printf("|%20s|\n", NULL);                   // Width with null pointer
	test_printf("|%-20s|\n", NULL);                  // Left-justified null pointer
	test_printf("|%s|\n", "");                       // Empty string
	test_printf("|%s|\n", " ");                      // Single space

	// Misordered Flags, Width, Precision
	test_printf("|%0-.5s|\n", "Misordered");         // Precision before flag '0' (undefined)
	test_printf("|%5-.s|\n", "Wrong Order");         // Width, then flag '-', then precision (undefined)
	test_printf("|%.5-5s|\n", "Confusing");          // Precision with width after '-' (undefined)
	test_printf("|%-0.s|\n", "Flags Mix");           // Conflicting flags and precision (undefined)
	test_printf("|%0#-s|\n", "Invalid Mix");         // Conflicting and invalid flags '#' and '0' (undefined)

	// Stress Testing
	test_printf("|%50s|\n", "Very long width!");     // Large width
	test_printf("|%.50s|\n", "Very long precision that exceeds the string!"); // Excessive precision
	test_printf("|%100s|\n", "Short string");        // Very large width with short string
	test_printf("|%-100s|\n", "Left-justified long width"); // Large width left-justified
	test_printf("|%100.20s|\n", "Short and truncated Hello"); // Large width and small precision
	test_printf("|%100.20s|\n", "Short and truncated"); // Large width and small precision
	test_printf("|%-100.20s|\n", "Left, width and truncated"); // Large width, small precision

	// Multiple Arguments
	test_printf("|%s%s%s|\n", "A", "B", "C");        // Multiple strings back-to-back
	test_printf("|%20s%-20s%.5s|\n", "First", "Second", "Third"); // Mixed width, flags, and precision
	test_printf("|%-20.5s%20.5s%5s|\n", "One", "Two", "Three");  // Alignment and truncation
	test_printf("|%-10s%-10s%-10s%-10s%-10s|\n", "A", "B", "C", "D", "E"); // Many strings
	test_printf("|%5s %5s %5s|\n", "X", "Y", "Z");   // Spaced strings
	test_printf("|%-10.5s%-10.5s%-10.5s|\n", "AA", "BB", "CC");  // Truncated and justified
	test_printf("|%5s%5.10s%10.5s|\n", "Short", "LongerString", "Short"); // Mixed widths and precision

	// Complex Misordered Flags
	test_printf("|%-0-5s|\n", "Zero and Left");      // Conflicting and repeated '-' and '0' (undefined)
	test_printf("|%0-.5s|\n", "Precision Before");   // Precision before '0' flag (undefined)
	test_printf("|%-.5s|\n", "Truncation Order");    // '-' before precision (undefined)
	test_printf("|%5-.s|\n", "Width Before Flag");   // Width, then '-' and precision (undefined)

}
