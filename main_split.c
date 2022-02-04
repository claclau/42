#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

#include "libft.h"

static unsigned int     ft_nb_words(char const *s, char c)
{
        unsigned int    i;
        unsigned int    nb_words;

        i = 1;
        nb_words = 0;
        if (s[0] == '\0')
                return (0);
        while (s[i])
        {
                if (s[i] == c && s[i - 1] != c)
                        nb_words++;
                i++;
        }
        if (s[i - 1] != c)
                nb_words++;
        return (nb_words);
}

static unsigned int     *ft_len_words(char const *s, char c)
{
        unsigned int    i;
        unsigned int    j;
        unsigned int    *list_len;
        unsigned int    len_word;

        i = 0;
        j = 0;
        list_len = malloc(sizeof(unsigned int) * ft_nb_words(s, c));
        if (!list_len)
                return (NULL);
        while (s[i])
        {
                len_word = 0;
                if (s[i] && s[i] != c)
                {
                        while (s[i] && s[i] != c)
                        {
                                len_word++;
                                i++;
                        }
                        list_len[j++] = len_word;
                }
                i++;
        }
        return (list_len);
}

int	main(void)
{
        char            s[24] = "ajda ajd jwj   ";
        char            c = ' ';
        unsigned int    i = 0;
        unsigned int    j = 0;

        printf("nb words : %d\n", ft_nb_words(s, c));

        while (i < ft_nb_words(s, c))
        {
                printf("%d\n", (ft_len_words(s, c))[i]);
                i++;
        }

	while (j != ft_nb_words(s, c))
        {
                printf("%s\n", (ft_split(s, c))[j]);
                j++;
        }
	return (0);
}
