/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:54:16 by claclau           #+#    #+#             */
/*   Updated: 2022/05/04 17:35:50 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_is_format_ok(char c);
int		ft_treatment(char c, va_list args);
int		ft_treat_c(char c);
int		ft_treat_s(char *s);
int		ft_treat_p(long long unsigned ptr);
int		ft_treat_d(int d);
int		ft_treat_u(unsigned int u);
int		ft_treat_x(unsigned int x);
int		ft_treat_xx(unsigned int x);
int		ft_putchar(char c);
int		ft_decuint_len_base(long long unsigned int n, char *base);
int		ft_int_len(int n);
void	ft_putnbr_base_fd(long long unsigned int n, char *base, int fd);
void	ft_putunbr_fd(unsigned int n, int fd);

#endif 
