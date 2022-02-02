/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:41:36 by claclau           #+#    #+#             */
/*   Updated: 2021/12/10 17:47:01 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_lstadd_back(t_list **alst, t_list *new);
t_list	*ft_lstnew(void *);

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

