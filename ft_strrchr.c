/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:50:32 by claclau           #+#    #+#             */
/*   Updated: 2022/02/02 15:22:21 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == c)
			res = i;
		i++;
	}
	if (res)
		return ((char *)s + res);
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}
