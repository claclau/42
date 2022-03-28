#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <inttypes.h>


#include <unistd.h>
#include <stdarg.h>

void    ft_putchar_fd(char c, int fd)
{
        write(fd, &c, 1);
}

void    ft_putstr_fd(char *s, int fd)
{
        if (!s)
                return ;
        write(fd, s, strlen(s));
}


void    ft_putnbr_fd(int n, int fd)
{
        if (n == -2147483648)
        {
                ft_putstr_fd("-2147483648", fd);
                return ;
        }
        if (n < 0)
        {
                ft_putchar_fd('-', fd);
                n = -n;
        }
        if (n >= 10)
        {
                ft_putnbr_fd(n / 10, fd);
                ft_putnbr_fd(n % 10, fd);
        }
        if (n < 10)
                ft_putchar_fd(n + 48, fd);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putunbr_fd(n / 10, fd);
		ft_putunbr_fd(n % 10, fd);
	}
	if (n < 10)
		ft_putchar_fd(n + 48, fd);	
}

void    ft_putnbr_base_fd(int n, char	*base, int fd)
{
	int	len_base;

	len_base = strlen(base);
//        if (n == -2147483648)
//        {
//                ft_putstr_fd("-2147483648", fd);
//                return ;
//        }
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



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	to_print;

	i = 0;
	va_start(to_print, format);
	
	while (format[i]) // we're gonna print the given string until we find a %something
	{
		if (format[i] == '%')
		{
			i++;

			// Depending on what %smth we have we should make several cases


			// %c -----------------------------------------------------------------

			if (format[i] == 'c')
			{
				char	char_value;
				char_value = (char)va_arg(to_print, int);
				write(1, &char_value, 1);
			}
		
			
			// %s ----------------------------------------------------------------
			
			if (format[i] == 's')
			{
				char	*str_value;
				str_value = (char *)va_arg(to_print, char*);
				write(1, str_value, strlen(str_value));
			}


			// %p -----------------------------------------------------------------

			if (format[i] =='p')
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
			

			// %d ----------------------------------------------------------------
			// nombre "decimal" ??? %d pour moi c'est un signed int

			if (format[i] == 'd')
			{
				
				int	int_value;
				int_value = va_arg(to_print, int);
				ft_putnbr_fd(int_value, 1);
			}


			// %i -----------------------------------------------------------------
			// je vois pas la diff avec %d
			

			// %u -----------------------------------------------------------------

			if (format[i] == 'u')
			{
				unsigned int	uint_value;
				uint_value = va_arg(to_print, unsigned int);
				ft_putunbr_fd(uint_value, 1);

			}
			

			// %x -----------------------------------------------------------------

			if (format[i] == 'x')
			{
				int	int_value2;
				int_value2 = va_arg(to_print, int);
				ft_putnbr_base_fd(int_value2, "0123456789abcdef", 1);

			}
			// probleme : printf ne gere pas les nombres negatifs, ma fonction si


			// %X -----------------------------------------------------------------

                        if (format[i] == 'X')
                        {
                                int     int_value3;
                                int_value3 = va_arg(to_print, int);
                                ft_putnbr_base_fd(int_value3, "0123456789ABCDEF", 1);

                        }
                        // probleme : printf ne gere pas les nombres negatifs, ma fonction si


			// %% ----------------------------------------------------------------

			if (format[i] == '%')
			{
				ft_putchar_fd('%', 1);
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
	return (i);
}

int	main(void)
{
	int	d = 42;
	int	*ptr = &d;
        printf("printf : %p\n", ptr);
        ft_printf("mine : %p\n", ptr);
// d = 4
// c = 1
//

	return (0);
}
