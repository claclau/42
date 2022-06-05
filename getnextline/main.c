#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <unistd.h>

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	i = 0;

	while (i < 10)
	{
		printf("\n\nTEST\n");
		fd = open("./test", O_RDONLY);
		printf("%s", get_next_line(fd));
		close(fd);

		i++;
	}

	return (0);
}
