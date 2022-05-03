#include "../libft/libft.h"

unsigned int    ft_decint_len_base(long long unsigned int n, char *base)
{
        unsigned int    len;
        unsigned int    len_base;

        len_base = ft_strlen(base);
        len = 0;
        if (n == 0)
		return (1);
        while (n > 0)
        {
                n /= len_base;
                len++;
        }
        return (len);
} 
