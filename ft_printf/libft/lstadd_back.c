/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:12:47 by claclau           #+#    #+#             */
/*   Updated: 2021/12/10 13:53:51 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *list);

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	(ft_lstlast(*alst))->next = new;
}
