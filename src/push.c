/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:42:05 by marcgar2          #+#    #+#             */
/*   Updated: 2024/12/21 14:42:05 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push(t_list **stack_src, t_list **stack_dst)
{
	t_list	*tmp;
	
	if (ft_lstsize(*stack_src) == 0)
		return (-1);
	
	tmp = *stack_src; // Guarda el nodo de stack_src
	*stack_src = (*stack_src)->next; // Avanza stack_src
	tmp->next = *stack_dst; // Conecta el nodo movido con stack_dst
	*stack_dst = tmp; // Actualiza stack_dst
	return (0);
}
int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}