/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:10:08 by marcgar2          #+#    #+#             */
/*   Updated: 2024/12/29 23:10:08 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	calc_subgroup_size(int total_nodes, int k)
{
	return (total_nodes + k - 1) / k; // Elementos + subgrupos creados - 1 / numero de subgrupos = tamaño de cada grupo
}

void	move_a_to_b(t_list **stack_a, t_list **stack_b, int max, int min)
{
	int	size;
	int	i;
	int value;

	size = ft_lstsize(*stack_a);
	i = 0;
	
	while (i < size)
	{
		value = (*stack_a)->index;
		if (value >= min && value <= max) // Si los numeros estan en el conjunto de min number < todos los nodos Y todos_los_nodos > max number
			pb(stack_a, stack_b); // PA para hacer subgrupos
		else
			ra(stack_a);
		i++;
	}
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

	total_nodes = ft_lstsize(*stack_a);
	subgroup_size = calc_subgroup_size(total_nodes, k);
	min = 0;
	max = subgroup_size - 1;
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