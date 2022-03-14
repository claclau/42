/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:19:53 by claclau           #+#    #+#             */
/*   Updated: 2021/12/03 12:32:26 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len_nb(int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res_str;
	int		len_nb;

	len_nb = ft_len_nb(n);
	if (n < 0)
		len_nb++;
	res_str = malloc(sizeof(char) * (len_nb + 1));
	if (!res_str)
		return (NULL);
	res_str[len_nb] = '\0';
	if (n == 0)
		res_str[0] = '0';
	if (n == -2147483648)
		return ("-2147483648");
	if (n < 0)
	{
		res_str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		res_str[--len_nb] = n % 10 + 48;
		n /= 10;
	}
	return (res_str);
}
