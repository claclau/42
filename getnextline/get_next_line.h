#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *string);
char    *ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void    *ft_memset(void *s, int c, size_t n);
void    ft_bzero(void *s, size_t n);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strchr(const char *s, int c);



#endif
