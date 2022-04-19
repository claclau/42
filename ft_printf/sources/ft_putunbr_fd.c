#include "../libft/libft.h"

void    ft_putunbr_fd(unsigned int n, int fd)
{
        if (n >= 10)
        {
                ft_putunbr_fd(n / 10, fd);
                ft_putunbr_fd(n % 10, fd);
        }
        if (n < 10)
                ft_putchar_fd(n + 48, fd);
}
