#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

//#define BUFFER_SIZE

#include <stdio.h>

// Go through buffer_line until you find a \n ; get lenght with i ; malloc given lenght and copy string up to \n into newline
char	*get_new_line(char *buffer_line)
{
	int	i;
	char	*newline;

	i = 0;
	while (buffer_line[i] && buffer_line[i] != '\n')
		i++;
	if (buffer_line[i] && buffer_line[i] == '\n')
		i++;
	newline = malloc(sizeof(char) * (i + 1));
	if (!newline)
	{
		free(buffer_line);
		return (NULL);
	}
	ft_bzero(newline, i + 1);
	newline = ft_substr(buffer_line, 0, i);
	return (newline);
}

// Read file BUFFER_SIZE byte by BUFFER_SIZE byte until you find a \n or EOF
char	*read_buffer_line(int fd)
{
	char	*buffer;
	char	*buffer_line;
	int	cr_not_found;
	int	read_ret;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	buffer_line = malloc(5000); // PAS OUF
	if (!buffer_line)
		return (NULL);
	ft_bzero(buffer_line, 5000);
	cr_not_found = 1;
	read_ret = 1;

	while (cr_not_found && read_ret)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		buffer[read_ret] = '\0';
		buffer_line = ft_strjoin(buffer_line, buffer);
		if (ft_strchr(buffer, '\n'))
			cr_not_found = 0;

	}
	free(buffer);
	return (buffer_line);
}

char	*get_next_line(int fd)
{
	
	char	*dump;
	static int	cr_index;
	char	*buffer_line;
	char	*line;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dump = malloc(cr_index);
	if (!dump)
		return (NULL);
	ft_bzero(dump, cr_index);

	
	if (read(fd, dump, cr_index) == -1)
	{
		free(dump);
		return (NULL);
	}

	buffer_line = malloc(5000); // PAS OUF
	if (!buffer_line)
	{
		free(dump);
		return (NULL);
	}
	ft_bzero(buffer_line, 5000);

	line = malloc(5000); // PAS OUF
	if (!line)
	{
		free(dump);
		free(buffer_line);
		return (NULL);
	}
	ft_bzero(line, 5000);

	buffer_line = read_buffer_line(fd);

	line = get_new_line(buffer_line);
	cr_index += ft_strlen(line);


	free(buffer_line);
	free(dump);

	return (line);
}
