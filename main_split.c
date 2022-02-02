#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

unsigned int	ft_nb_words(const char *s, char c);
unsigned int	*ft_len_words(const char *s, char c);
char	**ft_split2(char const *s, char c, char **split_str);
char	**ft_split(char const *s, char c);

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
