#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <unistd.h>

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test", O_RDONLY);
	
	line = "";

	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}

	close(fd);

	return (0);
}
