/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:15:34 by claclau           #+#    #+#             */
/*   Updated: 2022/02/02 15:35:11 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (ft_memcmp(dest, src, 15) < 0)
	{
		while (i < n)
		{
			ft_memset(dest + i, ((char *)src)[i], 1 * sizeof(char));
			i++;
		}		
	}
	else if (ft_memcmp(dest, src, 15) > 0)
	{
		while (n-- != 0)
			ft_memset(dest + n, ((char *)src)[n], 1 * sizeof(char));
	}
	return ((void *)dest);
}

/*
 * Si dest avant source
 * 
 * => cpy front to back
 *
 * Sinon,  dest apres source
 *
 * => cpy back to front
 */
