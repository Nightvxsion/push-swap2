/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseRotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:10:05 by marcgar2          #+#    #+#             */
/*   Updated: 2024/12/21 15:10:05 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	reverseRotate(t_list **stack)
{
	t_list	*head;
	t_list	*end;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	end = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL) // Encontrar el penultimo nodo
		{
			head->next = NULL; // Accion de asignar el ultimo nodo
			break;
		}
		head = head->next; // Actualizar el siguiente nodo a posicion actual
	}
	end->next = *stack;
	*stack = end;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (reverseRotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (reverseRotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	reverseRotate(stack_a);
	reverseRotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
