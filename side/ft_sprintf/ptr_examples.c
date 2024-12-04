#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *ptr = malloc(14);
	printf("Default:	|%p|	|	Flag: '030':	|%030p|\n", ptr, ptr);
	printf("Default:	|%p|	|	Flag: '30':		|%30p|\n", ptr, ptr);
	printf("Default:	|%p|	|	Flag: '-30':	|%-30p|\n", ptr, ptr);
	printf("Default:	|%p|	|	Flag: '.30':	|%.30p|\n", ptr, ptr);

	printf("Default:	|%p|	|	Flag: '030':	|%030p|\n", NULL, NULL);
	printf("Default:	|%p|	|	Flag: '30':		|%30p|\n", NULL, NULL);
	printf("Default:	|%p|	|	Flag: '-30':	|%-30p|\n", NULL, NULL);
	printf("Default:	|%p|	|	Flag: '.30':	|%.30p|\n", NULL, NULL);

	printf("Default:	|%p|	|	Flag: '03':	|%03p|\n", NULL, NULL);
	printf("Default:	|%p|	|	Flag: '3':		|%3p|\n", NULL, NULL);
	printf("Default:	|%p|	|	Flag: '-3':	|%-3p|\n", NULL, NULL);
	printf("Default:	|%p|	|	Flag: '.3':	|%.3p|\n", NULL, NULL);

	printf("Default:	|%x|	|	Flag: '030':	|%#030x|\n", ptr, ptr);
	printf("Default:	|%x|	|	Flag: '30':		|%#30x|\n", ptr, ptr);
	printf("Default:	|%x|	|	Flag: '-30':	|%#-30x|\n", ptr, ptr);
	printf("Default:	|%x|	|	Flag: '.30':	|%#.30x|\n", ptr, ptr);

	printf("Default:	|%x|	|	Flag: '030':	|%#030x|\n", NULL, NULL);
	printf("Default:	|%x|	|	Flag: '30':		|%#30x|\n", NULL, NULL);
	printf("Default:	|%x|	|	Flag: '-30':	|%#-30x|\n", NULL, NULL);
	printf("Default:	|%x|	|	Flag: '.30':	|%#.30x|\n", NULL, NULL);

	printf("Default:	|%p|	|	Flag: '+30':	|%+030p|\n", ptr, ptr);
	printf("Default:	|%p|	|	Flag: '+30':		|%+30p|\n", ptr, ptr);
	printf("Default:	|%p|	|	Flag: '+30':	|%+-30p|\n", ptr, ptr);
	printf("Default:	|%p|	|	Flag: '+.30':	|%+.30p|\n", ptr, ptr);

	printf("Default:	|%p|	|	Flag: '+30':	|% 030p|\n", ptr, ptr);
	printf("Default:	|%p|	|	Flag: '+30':	    |% 30p|\n", ptr, ptr);
	printf("Default:	|%p|	|	Flag: '+30':	|% -30p|\n", ptr, ptr);
	printf("Default:	|%p|	|	Flag: '+.30':	|% .30p|\n", ptr, ptr);
	free(ptr);
}
//
// if zero_flag exist
// 	print 0x, width - 2, and addr
// if !zero_flag 
// 	print width, and addr
// if left adjusted
// 	print addr and width
// if precision exist
// 	print 0x and 0s and addrs precision times
// if ptr == null
// 	print (nil)
