#include "test.h"
#include <stdio.h>

int main(void)
{
	 char char1 = 'A';
    char *str = "Hello, world!";
    char *null_str = NULL;
    void *ptr = (void *)0x12345678;
    int num = 42;
    unsigned int u_num = 123456789;
    unsigned int zero = 0;
    unsigned int max_uint = 0xFFFFFFFF;
	test_printf("|42% 12.8d42|\n", 0);
	test_printf("|^.^/%+44.16d^.^/|\n", 0);
	test_printf("|!%+29.57d!|\n", 839186175);
	test_printf("|32 this is an int : %0d\n\n|\n", 0);
	test_printf("|%102p|\n", (void *)9473888934885903032lu);
	test_printf("|%--190c|\n", 9);
	test_printf("|%--8.179x|\n", 505873219u);
	test_printf("|%91p|\n", (void *)13930816918730035186lu);
	test_printf("|%91p%--8.179x%--190c|\n", (void *)13930816918730035186lu, 505873219u, 9);
	test_printf("|%-186.138i%85p%-113c%--87p|\n", -1320475933, (void *)11899625258064503923lu, -39, (void *)15206197846470084523lu);
	test_printf("|%100d, %100d, %100d, %100d, %100d, %100d, %100d, %100d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	test_printf("| %04u |\n", 9);
	test_printf("| %01u |\n", 10);
	test_printf("| %04u |\n", 16);
	test_printf("| %05u |\n", 17);
	test_printf("| %01u |\n", 99);
	test_printf("| %012u |\n", LONG_MIN);
	test_printf("| %013u |\n", UINT_MAX);
	test_printf("| %014u |\n", ULONG_MAX);
	test_printf("| %015u |\n", 9223372036854775807ll);
	test_printf("| %09u %010u %011u %012u %013u %014u %015u|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	test_printf("| %01x |\n", 0);
	test_printf("| %04x |\n", 9);
	test_printf("| %01x |\n", 10);
	test_printf("| %03x |\n", 15);
	test_printf("| %04x |\n", 16);
	test_printf("| %05x |\n", 17);
	test_printf("| %01x |\n", 99);
	test_printf("| %01x |\n", -9);
	test_printf("| %010x |\n", INT_MIN);
	test_printf("| %#x |\n", 0);
	test_printf("| %#x |\n", LONG_MIN);
	test_printf("| %#x %#x %#x %#x %#x %#x %#x|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	test_printf("| %#x |\n", 0);
	test_printf("| %#x |\n", LONG_MIN);
	test_printf("| %#x %#x %#x %#x %#x %#x %#x|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	test_printf("|\\!/%- 18.2d\\!/|\n", 0);
	test_printf("|>------------<%#16.41x>------------<|\n", -1661147392);
	test_printf("|%.0u|\n", 0);
	test_printf("|%.u|\n", 0);
	test_printf("|%5.0u|\n", 0);
	test_printf("|%5.u|\n", 0);
	test_printf("|%-5.0u|\n", 0);
	test_printf("|%-5.u|\n", 0);
	test_printf("|%.0x|\n", 0);
	test_printf("|%.x|\n", 0);
	test_printf("|%5.0x|\n", 0);
	test_printf("|%5.x|\n", 0);
	test_printf("|%-5.0x|\n", 0);
	test_printf("|%-5.x|\n", 0);
	test_printf("|%.0x|\n", 0);
	test_printf("|%.x|\n", 0);
	test_printf("|%5.0x|\n", 0);
	test_printf("|%5.x|\n", 0);
	test_printf("|%-5.0x|\n", 0);
	test_printf("|%4%|\n", 0);
	test_printf("|%-5%|\n", 0);
	test_printf("|%-05%|\n", 0);
	test_printf("| %.1u |\n", 0);
	test_printf("| %.1x |\n", 0);
	test_printf("| %.1x |\n", 0);
	test_printf("|!%#19.2x!|\n", -130563600);
	test_printf("|%-#9.2x|\n", 144862103);
	test_printf("|%-#10.2x|\n", 144862103);
	test_printf("|\\!/%0#54x\\!/|\n", -2022925744);
	test_printf("|!%-#57.10x!|\n", -677125575);
	test_printf("|!%#38.32x!|\n", -1788945620);
	test_printf("|>------------<%#45.12x>------------<|\n", 1383915264);
	test_printf("|^.^/%-#54.50x^.^/|\n", 2035129755);
	test_printf("|%1.c|\n", 'a');
	test_printf("|%5.c|\n", 'a');
	test_printf("|%-+1.d, %-+1.d, %-+1.d, %-+1.d, %-+1.d, %-+1.d, %-+1.d, %-+1.d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	test_printf("|% #010x|\n", 1000);
	test_printf("|% +010x|\n", 1000);
	test_printf("|% +-010x|\n", 1000);
	test_printf("|% 010x|\n", 1000);
	test_printf("|% 010p|\n", 1000);
	test_printf("|% 0010p|\n", 1000);
	test_printf("|% 0010u|\n", 1000);
	test_printf("|% 0010x|\n", 1000);
	test_printf("|% +-0010x|\n", 1000);
	test_printf("|% +-0010d|\n", 1000);
	test_printf("|% +-0010i|\n", 1000);
	test_printf("|% +-0010.1i|\n", 1000);
	test_printf("|%+4p|\n", 1000);
	test_printf("|%+09p|\n", 1000);
	test_printf("|%+09p|\n", -1000);
	test_printf("|%+09p|\n", -1);
	test_printf("|%+19.10p|\n", -1);
	test_printf("|%+19.10p|\n", 0);
	test_printf("|%p|\n", 0);
	test_printf("|%2p|\n", 0);
	test_printf("|%29p|\n", 0);
	test_printf("|%-29p|\n", 0);
	test_printf("|%29.45p|\n", 0);
	test_printf("|%-29.45p|\n", 0);
	test_printf("|%-29.45p|\n", 6969);
	test_printf("|%-029.45p|\n", 6969);
	test_printf("|%+029.45p|\n", 6969);
	test_printf("|% 029.45p|\n", 6969);
	test_printf("|%029.45p|\n", 6969);
	test_printf("|%+u|\n", 6969);
	test_printf("|%+x|\n", 6969);
	test_printf("|%+x|\n", 6969);
	test_printf("|%-x%++-x|\n", 6968);
	test_printf("|%05%|\n");
	test_printf("|%010%|\n");
	test_printf("|%-135.109d|\n" , (void*)15603137398285451084lu,1482420587);
	test_printf("|%-171.108s|\n" ,"r>km,cwz,k7u");
	test_printf("|%-70.193x%-140c%168c%026.51%%0125.119x|\n" ,1102840003u,-50,-17,3721437512u);
	test_printf("|%10c%0036.99%|\n" ,9);
	test_printf("|%-89c%20p%-33.16x%--25.85u|\n" ,10,(void*)1144206967121894099lu,1538791465u,84, 543381790u);
	test_printf("|%p|\n", NULL);
	test_printf("|%.p|\n", NULL);
	test_printf("|%.p|\n", NULL);
	test_printf("|%1.p|\n", NULL);
	test_printf("|%1.p|\n", NULL);
	test_printf("|%5.p|\n", NULL);
	test_printf("|%5.p|\n", NULL);
	test_printf("|%5.x|\n", NULL);
	test_printf("|%5.u|\n", NULL);
	test_printf("|-->|%-16.p|<-- |\n", NULL);
	test_printf("|-->|%-16.p|<-- |\n", NULL);
	printf("\n::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("\n::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("\n::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("\n::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("\n::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("\n::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("\n::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("\n::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("\n::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("\n::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("\n::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("\n::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("\n::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("\n::::::::::::::::::::::::::::::::::::::::::::\n");
	test_printf("|%c|\n", char1);             // Single character
	test_printf("|%5c|\n", char1);            // Character with width
	test_printf("|%-5c|\n", char1);           // Left-justified character
	test_printf("|%05c|\n", char1);           // Zero-padded (undefined behavior for %c)
	test_printf("|%s|\n", str);               // Normal string
	test_printf("|%20s|\n", str);             // Right-justified string
	test_printf("|%-20s|\n", str);            // Left-justified string
	test_printf("|%.5s|\n", str);             // String truncated to precision
	test_printf("|%20.5s|\n", str);           // Combined width and precision
	test_printf("|%s|\n", null_str);          // NULL string (undefined behavior)
	test_printf("|%p|\n", ptr);               // Valid pointer
	test_printf("|%-20p|\n", ptr);            // Left-justified pointer
	test_printf("|%20p|\n", ptr);             // Right-justified pointer
	test_printf("|%p|\n", NULL);              // NULL pointer
	test_printf("|%d|\n", num);               // Normal signed integer
	test_printf("|%i|\n", num);               // Normal signed integer with %i
	test_printf("|%+d|\n", num);              // '+' flag
	test_printf("|% d|\n", num);              // ' ' (space) flag
	test_printf("|%-5d|\n", num);             // Left-justified
	test_printf("|%05d|\n", num);             // Zero-padded
	test_printf("|%.5d|\n", num);             // Precision
	test_printf("|%d|\n", 0);                 // Zero value
	test_printf("|%d|\n", -num);              // Negative value
	test_printf("|%u|\n", u_num);             // Unsigned integer
	test_printf("|%+u|\n", u_num);            // '+' flag (undefined behavior)
	test_printf("|% u|\n", u_num);            // ' ' (space) flag (undefined behavior)
	test_printf("|%05u|\n", u_num);           // Zero-padded
	test_printf("|%u|\n", zero);              // Zero value
	test_printf("|%u|\n", max_uint);          // Maximum unsigned value
	test_printf("|%x|\n", u_num);             // Lowercase hex
	test_printf("|%X|\n", u_num);             // Uppercase hex
	test_printf("|%#x|\n", u_num);            // Alternate form with "0x"
	test_printf("|%#X|\n", u_num);            // Alternate form with "0X"
	test_printf("|%05x|\n", u_num);           // Zero-padded
	test_printf("|%x|\n", zero);              // Zero value
	test_printf("|%#x|\n", zero);             // Alternate form with zero
	test_printf("|%y|\n", num);               // Invalid conversion specifier
	test_printf("|%w|\n", num);               // Invalid conversion specifier
	test_printf("|This is a test|\n");        // Normal string with no formatting
	test_printf("|%s %s|\n", "Multiple", "Strings");  // Multiple strings
	test_printf("|Hello, %% World!|\n");      // Escaped % with normal text
	test_printf("|%s|\n", "");                // Empty string
	test_printf("|%c|\n", '\0');              // Null character
	test_printf("|%10s|\n", "Short");         // Short string with larger width
	test_printf("|%.10s|\n", "Short");        // Short string with larger precision
	test_printf("|%010d|\n", 123);            // Zero-padded with width
	test_printf("|%-10s|\n", "Left");         //
}
