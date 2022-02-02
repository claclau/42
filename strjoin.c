/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:19:15 by claclau           #+#    #+#             */
/*   Updated: 2021/12/10 13:21:52 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *string);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*join_str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join_str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!join_str)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		join_str[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		join_str[i] = s2[i - len_s1];
		i++;
	}
	join_str[i] = '\0';
	return (join_str);
}
