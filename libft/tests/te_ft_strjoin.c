#include "../libft.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

size_t get_case()
{
    static size_t i = 0;
    return (i++);
}

void test_join(const char *s1, const char *s2, const char *exp)
{
    char *str = ft_strjoin(s1, s2);
    printf("---------------------------\n");
    printf("case number:		%zu\n", get_case());
    printf("s1:			\"%s\"\n", s1);
    printf("s2:			\"%s\"\n", s2);
    printf("expected:		\"%s\"\n", exp);
    printf("ft_strjoin:		\"%s\"\n", str);
    printf("\n");
    assert(strcmp(str, exp) == 0);
    free(str);
}

int main()
{
    test_join("Hello", ", World!", "Hello, World!");
    test_join("Goodbye", " Moon!", "Goodbye Moon!");
    test_join("OpenAI", " is amazing!", "OpenAI is amazing!");

    // Edge cases
    test_join("", "Empty", "Empty");
    test_join("Non-empty", "", "Non-empty");
    test_join("", "", "");

    // Special characters
    test_join("Line1\n", "Line2\n", "Line1\nLine2\n");
    test_join("Special", "Chars!@#", "SpecialChars!@#");
    test_join("Tab\t", "Character", "Tab\tCharacter");

    // Long strings
    char long1[1001], long2[1001];
    memset(long1, 'A', 1000);
    memset(long2, 'B', 1000);
    long1[1000] = '\0';
    long2[1000] = '\0';

    char expectedLong[2001];
    memset(expectedLong, 'A', 1000);
    memset(expectedLong + 1000, 'B', 1000);
    expectedLong[2000] = '\0';

    test_join(long1, long2, expectedLong); // Long string test

    // Repeated characters
    test_join("AAA", "BBB", "AAABBB");
    test_join("X", "Y", "XY");
    test_join("123", "456", "123456");

    // Mixed cases
    test_join("abc", "XYZ", "abcXYZ");
    test_join("1234", "5678", "12345678");
    test_join(NULL, NULL, "");
    test_join("Hi", NULL, "Hi");
    test_join(NULL, "HI", "HI");
}
