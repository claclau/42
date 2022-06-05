#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

#define BUFFER_SIZE 10

#include <stdio.h>

char	*get_next_line(int fd)
{
	// READ FILE BUFFER BY BUFFER UNTIL ONE WITH \n AND STORE INTO LINE
	
	char	*buffer;
	char	*buffer_line;
	char	*dump;
	int	cr_not_found;
	static int	cr_index;

//	printf("cr_index : %d\n", cr_index);

	buffer = malloc(BUFFER_SIZE);
	buffer_line = malloc(5000);
	ft_bzero(buffer_line, 5000);
	dump = malloc(5000);
	cr_not_found = 1;
	
	read(fd, dump, cr_index);
//	printf("dump : %s\n", dump);
	while (cr_not_found)
	{
		read(fd, buffer, BUFFER_SIZE);
//		printf("buffer : %s\n", buffer);
		buffer_line = ft_strjoin(buffer_line, buffer);
		if (ft_strchr(buffer, '\n'))
			cr_not_found = 0;
	}
//	printf("buffer line : %s\n", buffer_line);



	// GET LINE ENDING WITH \n
	
	int	i;
	char	*line;

	i = 0;
	line = malloc(5000);
	ft_bzero(line, 5000);

	while (buffer_line[i])
	{
		if (buffer_line[i] == '\n')
		{
			cr_index += i + 1;
//			printf("cr_index : %d\n", cr_index);
			line = ft_substr(buffer_line, 0, i + 1);
		}
		i++;
	}

	free(buffer);
	free(buffer_line);
	free(dump);

	return (line);
}
