#include <stdio.h>
#include <stdlib.h>


int main()
{
	static char *str;


	free(str);
	return (int) str;


}
