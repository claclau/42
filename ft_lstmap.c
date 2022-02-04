/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:56:24 by claclau           #+#    #+#             */
/*   Updated: 2022/02/03 16:59:01 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	
	new_list = ft_lstnew(NULL);
	if (lst && f)
	{
		new_list->content = f(lst->content);
		new_list->next = ft_lstmap(lst->next, f);
		return (new_list);
	}
	return (NULL);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!f)
		return (NULL);
	if (lst)
	{
		new_list = ft_lstnew(f(lst->content));
		while (lst->next)
		{
			lst = lst->next;
			new_elem = ft_lstnew(f(lst->content));
			ft_lstadd_back(&new_list, new_elem);
		}
	}
	return (new_list);
}
