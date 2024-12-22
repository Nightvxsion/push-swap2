/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:05:28 by marcgar2          #+#    #+#             */
/*   Updated: 2024/12/22 12:05:28 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_val(t_list **stack, int val)
{
	t_list	*head;
	int		value; // Donde se almacena el valor ignorado

	head = *stack;
	value = head->index;
	while (head->next)
	{
		head = head->next; // Actualizamos al siguiente valor
		if ((head->next < value) && head->next != value) // Si el siguiente valor NO ES menor que o igual que el valor a ignorar
			value = head->index; // Si se cumple entonces actualizamos la cabecera con el valor nuevo
	}
	return (value);
}

static void	sort3(t_list **stack)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack;
	min = get_min_val(stack, -1); // El indice mas pequeño de la lista
	next_min = get_min_val(stack, min); // El siguiente mas pequeño ignorado por min
	if (check_sort(stack))
		return;
	if ((head->index == min) && head->next->index != next_min) { //Si el primer nodo tiene el valor minimo Y si el segundo nodo NO tiene el segundo negativo aplicar ra, sa, rra.
		ra(stack);
		sa(stack);
		rra(stack);
	}
	else if (head->index == next_min) { // Si el primer nodo TIENE el segundo negativo y como subcaso si el segundo nodo tiene el valor negativo aplicar sa sino aplicar rra
		if (head->next->index == min)
			sa(stack);
		rra(stack);
	}
	else { // En esta condicion es que ya es el mas grande como subcaso tenemos que si el segundo nodo tiene el valor minimo aplicar ra y sino aplicar sa y rra
		if (head->next->index == min)
			ra(stack);
		sa(stack);
		rra(stack);
	}
}
