/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:20:13 by claclau           #+#    #+#             */
/*   Updated: 2021/12/10 13:27:40 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	res_str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res_str[i] = f(i, s[i]);
		i++;
	}
	res_str[i] = '\0';
	return (res_str);
}
