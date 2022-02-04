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

int	main(void)
{
        char            s[24] = "tripouille";
        char            c = 0;
	char	**tab;

        printf("nb words : %d\n", ft_nb_words(s, c));

	tab = ft_split("tripouille", 0);
	printf("%s\n", tab[0]);
	//printf("cmp : %d\n", strcmp(tab[0], "tripouille"));
	return (0);
}
