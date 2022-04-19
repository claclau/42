#include "../libft/libft.h"

void    ft_putnbr_base_fd(long long int n, char *base, int fd)
{
        unsigned int     len_base;

        len_base = ft_strlen(base);
        if (n < 0)
        {
                ft_putchar_fd('-', fd);
                n = -n;
        }
        if (n >= len_base)
        {
                ft_putnbr_base_fd(n / len_base, base, fd);
                ft_putnbr_base_fd(n % len_base, base, fd);
        }
        if (n < len_base)
                ft_putchar_fd(base[n], fd);
}
