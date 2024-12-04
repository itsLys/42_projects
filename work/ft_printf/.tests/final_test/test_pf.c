#include "ft_printf.h"
#include <limits.h>

int main()
{
	char c = 'A';
    char *str = "Hello, ft_printf!";
    char *null_str = NULL;
    void *ptr = (void *)0xDEADBEEF;
    int num = 42;
    int neg_num = -42;
    unsigned int u_num = 123456789;
    unsigned int zero = 0;
    unsigned int max_uint = 0xFFFFFFFF;

	ft_printf("|%c|\n", c);                  // Single character
    ft_printf("|%-5c|\n", c);               // Left-aligned character
    ft_printf("|%5c|\n", c);                // Right-aligned character
    ft_printf("|%05c|\n", c);               // Zero-padded (undefined behavior for %c)

    // **String (%s) Tests**
    ft_printf("|%s|\n", str);               // Normal string
    ft_printf("|%.5s|\n", str);             // Precision truncation
    ft_printf("|%-20s|\n", str);            // Left-aligned with width
    ft_printf("|%20s|\n", str);             // Right-aligned with width
    ft_printf("|%s|\n", null_str);          // NULL string

    // **Pointer (%p) Tests**
    ft_printf("|%p|\n", ptr);               // Valid pointer
    ft_printf("|%p|\n", NULL);              // NULL pointer
    ft_printf("|%-20p|\n", ptr);            // Left-aligned pointer
    ft_printf("|%20p|\n", ptr);             // Right-aligned pointer

    // **Signed Integer (%d, %i) Tests**
    ft_printf("|%d|\n", num);               // Normal integer
    ft_printf("|%i|\n", num);               // Integer with %i
    ft_printf("|%+d|\n", num);              // Sign flag
    ft_printf("|% d|\n", num);              // Space flag
    ft_printf("|%-10d|\n", num);            // Left-aligned with width
    ft_printf("|%010d|\n", num);            // Zero-padded
    ft_printf("|%.5d|\n", num);             // Precision specifier
    ft_printf("|%d|\n", 0);                 // Zero value
    ft_printf("|%d|\n", neg_num);           // Negative value

    // **Unsigned Integer (%u) Tests**
    ft_printf("|%u|\n", u_num);             // Unsigned integer
    ft_printf("|%u|\n", zero);              // Zero value
    ft_printf("|%u|\n", max_uint);          // Maximum unsigned value
    ft_printf("|%-10u|\n", u_num);          // Left-aligned with width
    ft_printf("|%010u|\n", u_num);          // Zero-padded
    ft_printf("|%+u|\n", u_num);            // '+' flag (undefined for %u)
    ft_printf("|% u|\n", u_num);            // Space flag (undefined for %u)

    // **Hexadecimal (%x, %X) Tests**
    ft_printf("|%x|\n", u_num);             // Lowercase hex
    ft_printf("|%X|\n", u_num);             // Uppercase hex
    ft_printf("|%#x|\n", u_num);            // Alternate form with "0x"
    ft_printf("|%#X|\n", u_num);            // Alternate form with "0X"
    ft_printf("|%x|\n", zero);              // Zero value
    ft_printf("|%#x|\n", zero);             // Alternate form with zero
    ft_printf("|%-10x|\n", u_num);          // Left-aligned
    ft_printf("|%010x|\n", u_num);          // Zero-padded

    // **Percent (%%) Tests**
    ft_printf("|%%|\n");                    // Literal '%'
    ft_printf("|%% %% %%|\n");              // Multiple literal '%'

    // **Invalid Conversion Specifiers**
    ft_printf("|%z|\n", num);               // Invalid specifier
    ft_printf("|%q|\n", num);               // Another invalid specifier
    ft_printf("|%y|\n", num);               // Random invalid specifier

    // **Edge Cases**
    ft_printf("|%s|\n", "");                // Empty string
    ft_printf("|%c|\n", '\0');              // Null character
    ft_printf("|%d|\n", INT_MIN);           // Minimum integer value
    ft_printf("|%d|\n", INT_MAX);           // Maximum integer value
    ft_printf("|%u|\n", 0U);                // Zero as unsigned integer
    ft_printf("|%u|\n", UINT_MAX);          // Maximum unsigned value
    ft_printf("|%p|\n", NULL);              // Null pointer
    ft_printf("|%x|\n", 0);                 // Hexadecimal zero
    ft_printf("|%s|\n", NULL);              // NULL string (should handle gracefully)

    // **Malformed Format Strings**
    ft_printf("|%|\n");                     // Lone '%'
    ft_printf("|%5|\n", num);               // Width but no specifier
    ft_printf("|%.|\n", num);               // Precision but no specifier
    ft_printf("|%\n");                      // '%' followed by newline
    ft_printf("|%5.5\n");                   // Width and preci
}
