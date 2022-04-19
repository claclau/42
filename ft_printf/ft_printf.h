#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stdint.h>

int		ft_printf(const char *format, ...);
unsigned int	ft_decint_len_base(long long int n, char *base);
unsigned int	ft_int_len(int n);
void		ft_putnbr_base_fd(long long int, char *base, int fd);
void		ft_putunbr_fd(unsigned int n, int fd);
unsigned int	ft_uint_len(unsigned int n);

#endif 
