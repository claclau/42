#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <inttypes.h>


#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#include "../libft/libft.h"

unsigned int	ft_int_len(int n);
unsigned int	ft_uint_len(unsigned int n);
unsigned int    ft_decint_len_base(long long int n, char *base); //remplace les deux du dessus ?

void		ft_putunbr_fd(unsigned int n, int fd);

void    ft_putnbr_base_fd(long long int n, char	*base, int fd); //remplacerait aussi celle du dessus


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int	ft_printf(const char *format, ...)
{
	int		i;
	va_list		to_print;
	unsigned int	nb_char_printed;
	int	nb_arg;

	i = 0;
	va_start(to_print, format);
	nb_char_printed = 0;
	nb_arg = 0;
	
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			nb_arg++;


			if (format[i] == 'c')
			{
				char	char_value;
				char_value = (char)va_arg(to_print, int);
				write(1, &char_value, 1);
				nb_char_printed++;
			}
		
			
			else if (format[i] == 's')
			{
				char	*str_value;
				str_value = (char *)va_arg(to_print, char*);
				write(1, str_value, strlen(str_value));
				nb_char_printed += strlen(str_value);
			}


/*			if (format[i] =='p')
			{
				void	*ptr_value;
				ptr_value = (void *)va_arg(to_print, void *);
				int	j = 5;
				int	var;
				write(1, "0x", 2);
				while (j >= 0)
				{
					var = ((long unsigned int)ptr_value >> 8*j) & 0xff;
					ft_putnbr_base_fd(var, "0123456789abcdef", 1);
					j--;
				}
			}
			*/
			else if (format[i] == 'p')
			{
				uintptr_t	ptr_value;
				ptr_value = (uintptr_t)va_arg(to_print, uintptr_t);
				write(1, "0x", 2);
				ft_putnbr_base_fd((long long int)ptr_value, "0123456789abcdef", 1);
				nb_char_printed += 14;
			}
			

			else if ((format[i] == 'd') || (format[i] == 'i'))
			{
				
				int	int_value;
				int_value = va_arg(to_print, int);
				ft_putnbr_fd(int_value, 1);
				nb_char_printed += ft_int_len(int_value);
			}


			else if (format[i] == 'u')
			{
				unsigned int	uint_value;
				uint_value = va_arg(to_print, unsigned int);
				ft_putunbr_fd(uint_value, 1);
				nb_char_printed += ft_uint_len(uint_value);
			}
			

			else if (format[i] == 'x')
			{
				long long int	int_value2;
				int_value2 = va_arg(to_print, long long int);
				ft_putnbr_base_fd(int_value2, "0123456789abcdef", 1);
				nb_char_printed += ft_decint_len_base(int_value2, "0123456789abcdef");
			}


			else if (format[i] == 'X')
                        {
                                long long int     int_value3;
                                int_value3 = va_arg(to_print, long long int);
                                ft_putnbr_base_fd(int_value3, "0123456789ABCDEF", 1);
				nb_char_printed += ft_decint_len_base(int_value3, "0123456789ABCDEF");
                        }


			else if (format[i] == '%')
			{
				ft_putchar_fd('%', 1);
				nb_char_printed++;
			}
			else /// voir si on garde
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				nb_arg--;
			}
			i++;

		}
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(to_print);
	return (i + nb_char_printed - nb_arg * 2);
}
