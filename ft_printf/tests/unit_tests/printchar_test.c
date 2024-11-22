#include "test.h"


int main(void)
{
	// Valid tests with combinations of flags, widths, and "c" conversion
	test_printf("|%c|\n", 'A');       // Left-justify
	test_printf("|%-c|\n", 'A');       // Left-justify
	test_printf("|%+c|\n", 'B');       // Undefined behavior: "+" not valid for "c"
	test_printf("|% c|\n", 'C');       // Space flag (no visible effect for "c")
	test_printf("|%#c|\n", 'D');       // Undefined behavior: "#" not valid for "c"
	test_printf("|%0c|\n", 'E');       // Undefined behavior: "0" not valid for "c"

	test_printf("|%-5c|\n", 'F');      // Left-justify with field width
	test_printf("|%5c|\n", 'G');       // Right-justify with field width
	test_printf("|% 5c|\n", 'H');      // Space flag with field width

	// Undefined behavior with precision (not valid for "c|\n")
	test_printf("|%.5c|\n", 'I');
	test_printf("|%5.3c|\n", 'J');
	test_printf("|%-5.2c|\n", 'K');

	// Width and invalid flags
	test_printf("|%0-5c|\n", 'L');     // Undefined: conflicting flags "0" and "-"
	test_printf("|%+#5c|\n", 'M');     // Undefined: combining invalid "+" and "#"

	// Undefined character inputs
	test_printf("|%c|\n", 0);          // Null character (valid but potentially surprising output)
	test_printf("|%c|\n", -1);         // Undefined behavior: invalid character value
	test_printf("|%c|\n", 300);        // Undefined behavior: out of `unsigned char` range
	test_printf("|%c|\n", 128);        // Undefined behavior: high ASCII (platform-dependent)

	// Escaped inputs
	test_printf("|%c|\n", '\n');       // Newline character
	test_printf("|%c|\n", '\t');       // Tab character
	test_printf("|%c|\n", '\0');       // Null character in the format
	test_printf("|%c|\n", '\\');       // Backslash character

	// Combinations of valid and undefined behaviors
	test_printf("|%-05c|\n", 'N');     // Undefined: conflicting flags "-" and "0"
	test_printf("|%0#c|\n", 'O');      // Undefined: invalid "#" with "0"
	test_printf("|%5.c|\n", 'P');      // Undefined: precision with "c"

	// Miscellaneous
	test_printf("|%10c|\n", 'Q');      // Right-justify with larger field width
	test_printf("|%-10c|\n", 'R');     // Left-justify with larger field width
	test_printf("|% c|\n", ' ');       // Space flag with space character

	// Additional tests to expand coverage
	test_printf("|%-1c|\n", 'S');      // Minimum field width of 1 with left-justify
	test_printf("|%-20c|\n", 'T');     // Large field width with left-justify
	test_printf("|%c|\n", 65);         // ASCII value for 'A'
	test_printf("|%c|\n", 255);        // Edge case for unsigned char range
	test_printf("|%5c|\n", '\0');      // Null character with field width
	test_printf("|%c|\n", 0x7F);       // DEL character (ASCII 127)
	test_printf("|%c|\n", '\b');       // Backspace character
	test_printf("|%-10c|\n", 70);      // Left-justify with numeric input representing 'F'
	test_printf("|%-5c|\n", '\v');     // Vertical tab with left-justify
	test_printf("|%c|\n", 1);          // Non-printable ASCII control character
	// Multiple args
	test_printf("|%c%c|\n", 'A', 'B');            // Two characters back-to-back
	test_printf("|%c %c|\n", 'X', 'Y');           // Two characters with space in between
	test_printf("|%-5c%-5c|\n", 'A', 'B');        // Left-justify both with field width
	test_printf("|%5c%5c|\n", 'C', 'D');          // Right-justify both with field width
	test_printf("|%-5c%5c|\n", 'E', 'F');         // Mixed justification
	test_printf("|%c%c%c|\n", 'G', 'H', 'I');     // Three characters back-to-back
	test_printf("|%-c%-c%-c|\n", 'J', 'K', 'L');  // Three left-justified characters
	test_printf("|%5c %5c %5c|\n", 'M', 'N', 'O');// Three characters with spacing

	// Combining characters and edge cases
	test_printf("|%c%c|\n", '\n', '\t');          // Newline and tab together
	test_printf("|%c%c|\n", 0, '\0');             // Two null characters
	test_printf("|%c%c|\n", -1, 300);             // Undefined: invalid char values
	test_printf("|%c%c|\n", 'P', '\v');           // Printable and vertical tab
	test_printf("|%c %c|\n", '\b', 255);          // Backspace and edge of unsigned char

	// Mixed valid and undefined behavior in multi-argument calls
	test_printf("|%c%+c%#c|\n", 'Q', 'R', 'S');   // Valid and undefined flags
	test_printf("|%5c%5.2c|\n", 'T', 'U');        // Width and undefined precision
	test_printf("|%0c%-c|\n", 'V', 'W');          // Conflicting flags combined

	// Longer sequences for stress testing
	test_printf("|%c%c%c%c%c|\n", 'A', 'B', 'C', 'D', 'E');    // Five characters
	test_printf("|%-5c%-5c%-5c%-5c%-5c|\n", 'F', 'G', 'H', 'I', 'J'); // Left-justified with width
	test_printf("|%5c%5c%5c%5c%5c|\n", 'K', 'L', 'M', 'N', 'O');       // Right-justified with width

	// Mixed argument types (valid and invalid together)
	test_printf("|%c %c %c|\n", 'X', -1, 300);    // Valid and undefined character values
	test_printf("|%c %c|\n", 'Y', '\0');          // Printable and null character
	test_printf("|%c %c %c|\n", 128, 255, 'Z');  // High ASCII and valid characters
}
