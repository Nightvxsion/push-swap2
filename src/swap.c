/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:41:53 by marcgar2          #+#    #+#             */
/*   Updated: 2024/12/21 14:41:53 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_value;
	int		tmp_index;

	head = *stack;
	next = head->next;
	if (ft_lstsize(*stack) < 2 || (!head && !next)) {
		ft_err("Error while swaping!");
		return (-1);
	}
	tmp_value = head->value; // Guardamos tanto el valor y el indice del nodo
	tmp_index = head->index; // Lo mismo con el indice
	head->value = next->value; // next->value es el segundo nodo que pasa al primero
	head->index = next->index; // Lo mismo con el indice
	next->value = tmp_value; // Pasamos el valor del primero al segundo
	next->index = tmp_index; // Lo mismo con el índice
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}