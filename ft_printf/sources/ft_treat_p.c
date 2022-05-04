/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:09:29 by claclau           #+#    #+#             */
/*   Updated: 2022/05/04 14:14:56 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf.h"

int	ft_treat_p(long long unsigned ptr)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		ft_putnbr_base_fd(ptr, "0123456789abcdef", 1);
		return (ft_decint_len_base(ptr, "0123456789abcdef") + 2);
	}
}
