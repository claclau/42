/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:54:16 by claclau           #+#    #+#             */
/*   Updated: 2022/05/04 15:14:29 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_treat_c(char c);
int		ft_treat_s(char *s);
int		ft_treat_p(long long unsigned ptr);
int		ft_treat_d(int d);
int		ft_treat_u(unsigned int u);
int		ft_treat_x(unsigned int x);
int		ft_treat_xx(unsigned int x);
unsigned int	ft_decuint_len_base(long long unsigned int n, char *base);
unsigned int	ft_int_len(int n);
void		ft_putnbr_base_fd(long long unsigned int n, char *base, int fd);
void		ft_putunbr_fd(unsigned int n, int fd);

#endif 
