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
                return;
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
	{
                ft_putchar_fd(n + 48, fd);
	}
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

void    ft_putnbr_base_fd(long long int n, char	*base, int fd)
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

unsigned int	ft_int_len(int n)
{
	unsigned int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int	ft_printf(const char *format, ...)
{
	int		i;
	va_list		to_print;
	unsigned int	nb_char_printed;

	i = 0;
	va_start(to_print, format);
	nb_char_printed = 0;
	
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
				nb_char_printed++;
			}
		
			
			// %s ----------------------------------------------------------------
			
			else if (format[i] == 's')
			{
				char	*str_value;
				str_value = (char *)va_arg(to_print, char*);
				write(1, str_value, strlen(str_value));
				nb_char_printed += strlen(str_value);
			}


			// %p -----------------------------------------------------------------

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
			

			// %d ----------------------------------------------------------------

			else if ((format[i] == 'd') || (format[i] == 'i'))
			{
				
				int	int_value;
				int_value = va_arg(to_print, int);
				ft_putnbr_fd(int_value, 1);
				nb_char_printed += ft_int_len(int_value);
			}


			// %u -----------------------------------------------------------------

			else if (format[i] == 'u')
			{
				unsigned int	uint_value;
				uint_value = va_arg(to_print, unsigned int);
				ft_putunbr_fd(uint_value, 1);
				nb_char_printed += ft_int_len(uint_value);
			}
			

			// %x -----------------------------------------------------------------

			else if (format[i] == 'x')
			{
				long long int	int_value2;
				int_value2 = va_arg(to_print, long long int);
				ft_putnbr_base_fd(int_value2, "0123456789abcdef", 1);
			}


			// %X -----------------------------------------------------------------

			else if (format[i] == 'X')
                        {
                                long long int     int_value3;
                                int_value3 = va_arg(to_print, long long int);
                                ft_putnbr_base_fd(int_value3, "0123456789ABCDEF", 1);

                        }


			// %% ----------------------------------------------------------------

			else if (format[i] == '%')
			{
				ft_putchar_fd('%', 1);
				nb_char_printed++;
			}
			else /// voir si on garde
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
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
	return (i + nb_char_printed);
}

int	main(void)
{
	int	ret = printf("Hello\n");
        int	myret = ft_printf("Hello\n");
	printf("ret : %d\nmyret : %d\n", ret, myret);

	return (0);
}

// probleme : si je specifie un %someth avec someth pris en charge par printf et pas par ft_printf
//
// si je demande un %x ou %X et donne une string ou un pointeur, j'ai maintenant trop d'infos
// si je demande un %s et ne donne pas une string, segfault mais la mienne ecrit quand meme ce qu'il y a avant le %s
//
// sur la valeur de retour de ft_printf, avec %u
//
//
//
// a faire : valeur de retour %x et %X
