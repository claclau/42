/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:14:24 by claclau           #+#    #+#             */
/*   Updated: 2022/02/03 16:50:08 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void	*content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int	ft_lstsize(t_list *list);
t_list	*ft_lstlast(t_list *list);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *));

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%s\n",(char *)list->content);
		list = list->next;
	}
}

void	f(void *s)
{
	while (*(char *)s)
	{
		(*(char *)s)++;
		s++;
	}
}

void	*f2(void *s)
{
	char	*str;
	unsigned int	i;
	
	str = malloc(sizeof(char) * 100);
	i = 0;
	while (((char *)s)[i])
	{
		str[i] = 'a';
		i++;
	}
	return (str);
}

int	main(void)
{
	t_list *list;
	char s[50] = "Hello";
	list = NULL;
	list = ft_lstnew(s);


	t_list *list2;
	char s2[50] = "Goodbye";
	list2 = NULL;
	list2 = ft_lstnew(s2);

	t_list *listbonus;
	char sbonus[50] = "Goodbye";
	listbonus = NULL;
	listbonus = ft_lstnew(sbonus);
	
	// Afficher les deux elements
	print_list(list);
	print_list(list2);
	print_list(listbonus);
	
	printf("\n");
	// Ajouter l'element 2 au debut de la liste 1 ; afficher le nb d'elements de la liste 1
	ft_lstadd_front(&list, list2);
	print_list(list);
	printf("%d\n", ft_lstsize(list));

	ft_lstadd_front(&list, listbonus);
	print_list(list);
	printf("%d\n", ft_lstsize(list));
	
	
	printf("\n");
	// Afficher le dernier element de la liste
	printf("%s\n", (char *)(ft_lstlast(list))->content);


	printf("\n");	
	// Ajouter l'element 3 a la fin de la liste
	t_list	*list3;
	char s3[50] = "Pleaaase";
	list3 = NULL;
	list3 = ft_lstnew(s3);

	ft_lstadd_back(&list, list3);
	print_list(list);
	printf("%d\n", ft_lstsize(list));

/*
	printf("\n");
	// Iterer f() sur la liste
	ft_lstiter(list, &f);
	print_list(list);
*/	

	printf("\n");
	// Creer une nouvelle liste avec le resultat de l'iteration de f2() sur list
	t_list	*new_list;
	new_list = NULL;
	new_list = ft_lstmap(list, &f2);
	print_list(new_list);


	return (0);
}
