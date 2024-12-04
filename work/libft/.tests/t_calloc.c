#include "test.h"
#include "libft.h"
#include "stdint.h"
#include <stdio.h>


int main()
{

	void *str = calloc(SIZE_MAX - 1000, 2);
	printf("%zu\n", (SIZE_MAX - 1000) * 2);
	printf("%p", str);
}
