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
	test_printf("|%.5c|\n", 'I');
	test_printf("|%5.3c|\n", 'J');
	test_printf("|%-5.2c|\n", 'K');
	test_printf("|%0-5c|\n", 'L');     // Undefined: conflicting flags "0" and "-"
	test_printf("|%+#5c|\n", 'M');     // Undefined: combining invalid "+" and "#"
	test_printf("|%c|\n", 0);          // Null character (valid but potentially surprising output)
	test_printf("|%c|\n", -1);         // Undefined behavior: invalid character value
	test_printf("|%c|\n", 300);        // Undefined behavior: out of `unsigned char` range
	test_printf("|%c|\n", 128);        // Undefined behavior: high ASCII (platform-dependent)
	test_printf("|%c|\n", '\n');       // Newline character
	test_printf("|%c|\n", '\t');       // Tab character
	test_printf("|%c|\n", '\0');       // Null character in the format
	test_printf("|%c|\n", '\\');       // Backslash character
	test_printf("|%-05c|\n", 'N');     // Undefined: conflicting flags "-" and "0"
	test_printf("|%0#c|\n", 'O');      // Undefined: invalid "#" with "0"
	test_printf("|%5.c|\n", 'P');      // Undefined: precision with "c"
	test_printf("|%10c|\n", 'Q');      // Right-justify with larger field width
	test_printf("|%-10c|\n", 'R');     // Left-justify with larger field width
	test_printf("|% c|\n", ' ');       // Space flag with space character
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
	test_printf("|%c%c|\n", 'A', 'B');            // Two characters back-to-back
	test_printf("|%c %c|\n", 'X', 'Y');           // Two characters with space in between
	test_printf("|%-5c%-5c|\n", 'A', 'B');        // Left-justify both with field width
	test_printf("|%5c%5c|\n", 'C', 'D');          // Right-justify both with field width
	test_printf("|%-5c%5c|\n", 'E', 'F');         // Mixed justification
	test_printf("|%c%c%c|\n", 'G', 'H', 'I');     // Three characters back-to-back
	test_printf("|%-c%-c%-c|\n", 'J', 'K', 'L');  // Three left-justified characters
	test_printf("|%5c %5c %5c|\n", 'M', 'N', 'O');// Three characters with spacing
	test_printf("|%c%c|\n", '\n', '\t');          // Newline and tab together
	test_printf("|%c%c|\n", 0, '\0');             // Two null characters
	test_printf("|%c%c|\n", -1, 300);             // Undefined: invalid char values
	test_printf("|%c%c|\n", 'P', '\v');           // Printable and vertical tab
	test_printf("|%c %c|\n", '\b', 255);          // Backspace and edge of unsigned char
	test_printf("|%c%+c%#c|\n", 'Q', 'R', 'S');   // Valid and undefined flags
	test_printf("|%5c%5.2c|\n", 'T', 'U');        // Width and undefined precision
	test_printf("|%0c%-c|\n", 'V', 'W');          // Conflicting flags combined
	test_printf("|%c%c%c%c%c|\n", 'A', 'B', 'C', 'D', 'E');    // Five characters
	test_printf("|%-5c%-5c%-5c%-5c%-5c|\n", 'F', 'G', 'H', 'I', 'J'); // Left-justified with width
	test_printf("|%5c%5c%5c%5c%5c|\n", 'K', 'L', 'M', 'N', 'O');       // Right-justified with width
	test_printf("|%c %c %c|\n", 'X', -1, 300);    // Valid and undefined character values
	test_printf("|%c %c|\n", 'Y', '\0');          // Printable and null character
	test_printf("|%c %c %c|\n", 128, 255, 'Z');  // High ASCII and valid characters
	test_printf("|%--c|\n", 'A');         // Repeated '-' (undefined)
	test_printf("|%++c|\n", 'B');         // Repeated '+' (undefined)
	test_printf("|%00c|\n", 'C');         // Repeated '0' (undefined)
	test_printf("|%  c|\n", 'D');         // Repeated space (redundant, valid but pointless)
	test_printf("|%  -c|\n", 'E');        // Space and repeated '-' (undefined)
	test_printf("|%-0-5c|\n", 'F');       // Conflicting and repeated '-' and '0' (undefined)
	test_printf("|%00-5c|\n", 'G');       // Conflicting and repeated '0' with '-' (undefined)
	test_printf("|% 0- c|\n", 'H');       // Space, '0', and '-' combined (undefined)
	test_printf("|%---c|\n", 'I');        // Multiple '-' flags (undefined)
	test_printf("|%0-.5c|\n", 'J');       // Precision before flag '0' (undefined for %c)
	test_printf("|%5-.c|\n", 'K');        // Width, then flag '-', then precision (undefined)
	test_printf("|%.5-5c|\n", 'L');       // Precision with width after '-' (undefined)
	test_printf("|%-0.c|\n", 'M');        // Conflicting flags and precision (undefined)
	test_printf("|%0#-c|\n", 'N');        // Conflicting and invalid flags '#' and '0' (undefined)
	test_printf("|%05c|\n", 'O');         // Valid width with '0', but '0' has no effect (undefined for %c)
	test_printf("|%0-5c|\n", 'P');        // Conflicting '0' and '-' with width (undefined)
	test_printf("|%-#c|\n", 'Q');         // '-' with invalid '#' flag (undefined)
	test_printf("|%+0c|\n", 'R');         // '+' and '0' flags (undefined for %c)
	test_printf("|%#-5c|\n", 'S');        //
	test_printf("|%-0-5c|\n", 65);        // ASCII for 'A', invalid order of flags
	test_printf("|%--0c|\n", 66);         // ASCII for 'B', multiple flags in wrong order
	test_printf("|%-.5c|\n", 67);         // ASCII for 'C', precision before '-' (undefined)
	test_printf("|%.0-5c|\n", 68);        // ASCII for 'D', precision with '-' and width (undefined)
	test_printf("|%5-.2c|\n", 69);        // ASCII for 'E', width and precision misordered
	test_printf("|%5c|\n", 'T');          // Right-justified with width
	test_printf("|%-5c|\n", 'U');         // Left-justified with width
	test_printf("|%.5c|\n", 'V');         // Precision specified for %c (undefined)
	test_printf("|%5.3c|\n", 'W');        // Width with precision (undefined)
	test_printf("|%-5.2c|\n", 'X');       // Left-justified with precision (undefined)
	test_printf("|%0.5c|\n", 'Y');        // Flag '0' with precision (undefined for %c)
	test_printf("|%5.c|\n", 'Z');         // Width with empty precision (undefined)
	test_printf("|%-.5c|\n", 'A');        // '-' with precision (undefined)
	test_printf("|%5-.c|\n", 'B');        // Width, then '-' and precision (undefined)
	test_printf("|%-0-#5c|\n", 'F');      // Multiple conflicting flags and width (undefined)
	test_printf("|%5.0c|\n", 'G');        // Width with precision set to zero (undefined)
	test_printf("|%-0#-.5c|\n", 'H');     // Confusing combination of flags and precision (undefined)
	printf(":::::CHECK VALID\n");
	test_printf("|%0-0-.c|\n", 'I');      // Mixed order: '0', '-', width, precision (undefined)
	test_printf("|%-#05.3c|\n", 'J');     // Undefined with all invalid flags combined
	test_printf("|%0-5-.c|\n", 'I');      // Mixed order: '0', '-', width, precision (undefined)



}
