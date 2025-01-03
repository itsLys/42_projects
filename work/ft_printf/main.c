#include "ft_printf.h"
#include <stdio.h>




int main()
{
	close(1);
	int n = printf("Hello");
	return n;
}
