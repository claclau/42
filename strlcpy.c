/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:11:35 by claclau           #+#    #+#             */
/*   Updated: 2021/12/09 14:34:37 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

size_t	ft_strlen(const char *string);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	printf("%s\n", dst);
	return (ft_strlen(src));
}

// what if size > dst ?
// dst = 0 ? size = 0 ?
