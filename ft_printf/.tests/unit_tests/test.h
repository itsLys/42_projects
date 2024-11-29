#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
int get_case(void);
void test_printf(const char  *fmt, ...);
#define YELLOW "\e[33;1m"
#define RED "\e[31;1m"
#define RESET "\x1b[0m"
#define GREEN "\e[32m"
