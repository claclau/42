#include <unistd.h>
#include <stdlib.h>

#include "get_next_line.h"

#include <stdio.h>
#include <string.h>

char    *get_new_line(char *to_keep)
{
        int     i;
        char    *newline;

	if (!to_keep)
		return (NULL);
        i = 0;
        while (to_keep[i] && to_keep[i] != '\n')
                i++;
        if (to_keep[i] && to_keep[i] == '\n')
                i++;
        newline = malloc(sizeof(char) * (i + 1));
        if (!newline)
                return (NULL);
        newline = ft_substr(to_keep, 0, i);
        return (newline);
}

void	read_buffer_line(int fd, char **to_keep)
{
	char	*buffer;
	char	*tmp;
	int	cr_found;
	int	read_ret;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return;
	cr_found = 0;
	read_ret = 1;
	tmp = NULL;

	while (!cr_found && read_ret > 0)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		buffer[read_ret] = '\0';

		
		tmp = ft_strdup(*to_keep);
		*to_keep = ft_strjoin(tmp, buffer);

		if (ft_strchr(*to_keep, '\n'))
			cr_found = 1;
	}
	free(tmp);
	free(buffer);	
}



char	*get_next_line(int fd)
{
	static char	*to_keep;
	char		*line;

	line = NULL;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);

	read_buffer_line(fd, &to_keep);

	
	line = get_new_line(to_keep);
	to_keep = ft_substr(to_keep, ft_strlen(line), ft_strlen(to_keep) - ft_strlen(line));

	if (*line == '\0')
	{
		free(to_keep);
		free(line);
		return (NULL);
	}
	return (line);
}
