#include <stddef.h>
#include <stdlib.h>

size_t  ft_strlen(const char *string)
{
        size_t  len;

        len = 0;
        while (string[len])
                len++;
        return (len);
}

char    *ft_strdup(const char *s)
{
        size_t  str_len;
        size_t  i;
        char    *dup_str;

        str_len = ft_strlen(s);
        i = 0;
        dup_str = malloc(sizeof(char) * (str_len + 1));
        if (dup_str == NULL)
                return (NULL);
        while (s[i])
        {
                dup_str[i] = s[i];
                i++;
        }
        dup_str[i] = '\0';
        return (dup_str);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char                    *substr;
        unsigned int    i;

        if (!s)
                return (NULL);
        if (start > ft_strlen(s))
                return (ft_strdup(""));
        if (len > ft_strlen(s) - start)
                len = ft_strlen(s) - start;
        substr = malloc(sizeof(char) * (len + 1));
        if (substr == NULL)
                return (NULL);
        i = 0;
        while (s[start + i] && i < len)
        {
                substr[i] = s[start + i];
                i++;
        }
        substr[i] = '\0';
        return (substr);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        size_t  len_s1;
        size_t  len_s2;
        char    *join_str;
        size_t  i;

        if (!s1 || !s2)
                return (NULL);
        len_s1 = ft_strlen(s1);
        len_s2 = ft_strlen(s2);
        join_str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
        if (!join_str)
                return (NULL);
        i = 0;
        while (i < len_s1)
        {
                join_str[i] = s1[i];
                i++;
        }
        while (i < len_s1 + len_s2)
        {
                join_str[i] = s2[i - len_s1];
                i++;
        }
        join_str[i] = '\0';
        return (join_str);
}

char    *ft_strchr(const char *s, int c)
{
        int     i;

        i = 0;
        while (s[i])
        {
                if (s[i] == (char)c)
                        return ((char *)s + i);
                i++;
        }
        if (c == '\0')
                return ((char *)s + i);
        return (0);
}

void    *ft_memset(void *s, int c, size_t n)
{
        while (n-- != 0)
                ((char *)s)[n] = c;
        return (s);
}

void    ft_bzero(void *s, size_t n)
{
        ft_memset(s, '\0', n);
}

