/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:34:41 by claclau           #+#    #+#             */
/*   Updated: 2021/12/10 13:24:02 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned long	ft_strlen(const char *string);

int	ft_is_in_charset(char c, char const *set)
{
	unsigned long	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

unsigned long	ft_count_to_trim(char const *s1, char const *set)
{
	unsigned long	i;
	unsigned long	count;
	unsigned long	len_s1;

	i = 0;
	count = 0;
	if (s1[0] == '\0')
		return (0);
	len_s1 = ft_strlen(s1);
	while (ft_is_in_charset(s1[i], set))
	{
		count++;
		i++;
	}
	while (ft_is_in_charset(s1[--len_s1], set))
		count++;
	return (count);
}

unsigned long	ft_last_nonset_index(char const *s1, char const *set)
{
	unsigned long	index;

	if (s1[0] == '\0')
		return (0);
	index = ft_strlen(s1) - 1;
	while (ft_is_in_charset(s1[index], set))
		index--;
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed_str;
	unsigned long	i;
	unsigned long	j;

	trimmed_str = malloc(sizeof(char)
			* (ft_strlen(s1) - ft_count_to_trim(s1, set) + 1));
	if (!trimmed_str || !s1)
		return (NULL);
	i = 0;
	j = 0;
	while (ft_is_in_charset(s1[i], set))
		i++;
	while (i <= ft_last_nonset_index(s1, set))
	{
		trimmed_str[j] = s1[i];
		j++;
		i++;
	}
	if (s1[0] != '\0')
		trimmed_str[j] = '\0';
	return (trimmed_str);
}
