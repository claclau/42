#include "../libft/libft.h"

unsigned int    ft_int_len(int n)
{
        unsigned int    len;

        if (n == -2147483648)
                return (11);
        len = 0;
        if (n <= 0)
        {
                n = -n;
                len++;
        }
        while (n > 0)
        {
                n /= 10;
                len++;
        }
        return (len);
}
