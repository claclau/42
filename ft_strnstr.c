/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:48:01 by claclau           #+#    #+#             */
/*   Updated: 2022/02/02 15:24:10 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i] == little[j])
			{
				j++;
				i++;
			}
			if (j == ft_strlen(little))
				return ((char *)big + i - ft_strlen(little));
			i--;
		}
		i++;
	}
	return (NULL);
}
