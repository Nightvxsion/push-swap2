/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:22:34 by marcgar2          #+#    #+#             */
/*   Updated: 2024/12/26 23:22:34 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_list	*get_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		min_check;

	head = *stack;
	min = NULL;
	min_check = 0;
	if (head)
	{
		while(head)
		{
			if ((head->index == -1) && (!min_check || head->value < min->value)) // Si no tiene un minimo ya determinado o si el valor de la cabecera es menor que el valor de la lista
			{
				min = head;
				min_check = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_of_stack(t_list **stack_a)
{
	t_list	*head;
	int		main_index;

	main_index = 0;
	head = get_min(stack_a);
	while(head)
	{
		head->index = main_index++;
		head = get_min(stack_a);
	}
}