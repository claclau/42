/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:31:58 by claclau           #+#    #+#             */
/*   Updated: 2021/11/25 16:58:22 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strlen(const char *str);

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long size)
{
	unsigned long	dst_len;
	unsigned long	i;

	dst_len = ft_strlen(dst);
	if (size == 0)
		return (dst_len); // verifier ?
	i = 0;
	while (src[i] && (size + i < dst_len))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	return (dst_len + ft_strlen(src));
}

// pas bon mais flemme pour le moment
