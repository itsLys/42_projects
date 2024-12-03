#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char	*last;
	char	*line;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 0x7ffff000)
		return (NULL);

	return (line);
}
