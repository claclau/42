/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:23:51 by claclau           #+#    #+#             */
/*   Updated: 2022/05/04 15:58:47 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_treat_xx(unsigned int x)
{
	ft_putnbr_base_fd(x, "0123456789ABCDEF", 1);
	return (ft_decuint_len_base(x, "0123456789ABCDEF"));
}
