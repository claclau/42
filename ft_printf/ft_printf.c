/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:21:26 by claclau           #+#    #+#             */
/*   Updated: 2022/05/04 14:29:50 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		to_print;
	unsigned int	nb_char_printed;
	int			nb_arg;

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
				nb_char_printed += ft_treat_c(char_value);
			}
			else if (format[i] == 's')
			{
				char	*str_value;
				str_value = (char *)va_arg(to_print, char *);
				nb_char_printed += ft_treat_s(str_value);
			}
			else if (format[i] == 'p')
			{
				long long unsigned	ptr_value;
				ptr_value = (long long unsigned)va_arg(to_print, uintptr_t);
				nb_char_printed += ft_treat_p(ptr_value);
			}
			else if ((format[i] == 'd') || (format[i] == 'i'))
			{
				int	int_value;
				int_value = va_arg(to_print, int);
				nb_char_printed += ft_treat_d(int_value);
			}
			else if (format[i] == 'u')
			{
				unsigned int	uint_value;
				uint_value = va_arg(to_print, unsigned int);
				nb_char_printed += ft_treat_u(uint_value);
			}
			else if (format[i] == 'x')
			{
				unsigned int	int_value2;
				int_value2 = va_arg(to_print, unsigned int);
				nb_char_printed += ft_treat_x(int_value2);
			}
			else if (format[i] == 'X')
			{
				unsigned int	int_value3;
				int_value3 = va_arg(to_print, unsigned int);
				nb_char_printed += ft_treat_X(int_value3);
			}
			else if (format[i] == '%')
			{
				ft_putchar_fd('%', 1);
				nb_char_printed++;
			}
			else
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
