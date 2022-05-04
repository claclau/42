/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decuint_len_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:33:43 by claclau           #+#    #+#             */
/*   Updated: 2022/05/04 14:39:25 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

unsigned int	ft_decuint_len_base(long long unsigned int n, char *base)
{
	unsigned int	len;
	unsigned int	len_base;

	len_base = ft_strlen(base);
	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= len_base;
		len++;
	}
	return (len);
}
