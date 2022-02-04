/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:30:46 by claclau           #+#    #+#             */
/*   Updated: 2022/02/04 21:30:33 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nb_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_words;

	i = 1;
	nb_words = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			nb_words++;
		i++;
	}
	if (s[i - 1] != c)
		nb_words++;
	return (nb_words);
}

static unsigned int	*ft_len_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	*list_len;
	unsigned int	len_word;

	i = 0;
	j = 0;
	list_len = malloc(sizeof(unsigned int) * ft_nb_words(s, c));
	if (!list_len)
		return (NULL);
	while (s[i])
	{
		len_word = 0;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				len_word++;
				i++;
			}
			list_len[j++] = len_word;
		}
		i++;
	}
	return (list_len);
}

static char	**ft_split2(char const *s, char c, char **split_str)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = 0;
			while (s[i] && s[i] != c)
			{
				split_str[j][k] = s[i];
				i++;
				k++;
			}
			split_str[j][k] = '\0';
			j++;
		}
		i++;
	}
	return (split_str);
}

char	**ft_split(char const *s, char c)
{
	char			**split_str;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	split_str = malloc(sizeof(char *) * (ft_nb_words(s, c) + 1));
	while (i < ft_nb_words(s, c))
	{
		split_str[i] = malloc(sizeof(char) * ((ft_len_words(s, c))[i] + 1));
		if (!split_str[i])
			return (NULL);
		i++;
	}
	split_str[i] = NULL;
	return (ft_split2(s, c, split_str));
}
