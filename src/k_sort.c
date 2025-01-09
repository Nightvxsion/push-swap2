/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:10:08 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/09 19:03:37 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	calc_subgroup_size(int total_nodes, int k)
{
	return (total_nodes + k - 1) / k; // Elementos + subgrupos creados - 1 / numero de subgrupos = tamaño de cada grupo
}

void	move_a_to_b(t_list **stack_a, t_list **stack_b, int max, int min)
{
	int value;

	while (1)
	{
		value = find_closest(*stack_a, min, max);
		if (value == -1)
			break;
		make_top(stack_a, value);
		pb(stack_a, stack_b); // PA para hacer subgrupos
	}
}

int	find_closest(t_list *stack, int min, int max)
{
	t_list	*tmp;
	int		position;
	int		i;

	tmp = stack;
	position = -1;
	i = 0;
	while (tmp)
	{
		if (tmp->index >= min && tmp->index <= max)
		{
			position = i;
			break;
		}
		tmp = tmp->next;
		i++;
	}
	return (position);
}

void	move_b_to_a(t_list **stack_a, t_list **stack_b)
{
	while(ft_lstsize(*stack_b) > 0)
		pa(stack_a, stack_b);
}

void	k_sort(t_list **stack_a, t_list **stack_b, int k)
{
	int	total_nodes;
	int	subgroup_size;
	int	min;
	int	max;
	int	leng;

	total_nodes = ft_lstsize(*stack_a);
	subgroup_size = calc_subgroup_size(total_nodes, k);
	min = 0;
	max = subgroup_size - 1;
	leng = distance(stack_a);
	while (min < total_nodes)
	{
		move_a_to_b(stack_a, stack_b, min, max);
		min = max + 1; // Por donde empieza un grupo
		max = min + subgroup_size - 1; // Detectar el rango de los subgrupos
		if (max >= total_nodes) // Si el indice total supera el rango maximo
			max = total_nodes - 1; // Igualamos el indice maximo al numero anterior de todos los nodos existentes
	}
	move_b_to_a(stack_a, stack_b);
}
