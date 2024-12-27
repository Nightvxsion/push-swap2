/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:30:24 by marcgar2          #+#    #+#             */
/*   Updated: 2024/12/17 20:30:24 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->value = content;
	elem->index = 0;
	elem->next = NULL;
	return (elem);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (!lst)
		return (NULL);
	while (temp->next)
	{
		temp = temp->next;
		if (temp->next == NULL)
			return (temp);
	}
	return (temp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ulti;

	if (*lst)
	{
		ulti = ft_lstlast(*lst);
		ulti->next = new;
		new->next = NULL;
	}
	else
	{
		*lst = new;
		(*lst)->next = NULL;
	}
}

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	size_t	i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	printlist(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_putnbr_fd(tmp->value, 1);
		write(1, " ", 1);
		tmp = tmp->next;
	}
}