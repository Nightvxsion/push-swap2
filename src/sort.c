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

#include "../include/push_swap.h"

static int	get_min_val(t_list **stack, int val)
{
	t_list	*head;
	int		value; // Donde se almacena el valor ignorado

	head = *stack;
	value = head->index;
	while (head->next)
	{
		head = head->next; // Actualizamos al siguiente valor
		if ((head->index < value) && head->index != val) // Si el siguiente valor NO ES menor que o igual que el valor a ignorar (parametro)
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

static void	sort4(t_list **stack_a, t_list	**stack_b)
{
	int	len;

	if (check_sort(stack_a))
		return;
	len = distance(stack_a, get_min_val(stack_a, -1)); // Distancia del stack a, pero sabiendo el elemnto mas pequeño
	if (len == 1)
		ra(stack_a);
	else if (len == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (len == 3)
		rra(stack_a);
	pb(stack_a, stack_b); // Guardamos arista
	sort3(stack_a); // Ordenamos los 3 elementos que quedan
	pa(stack_a, stack_b); // Insertamos arista
}

void	sort5(t_list **stack_a, t_list **stack_b)
{
	int	len; // Lo mismo que en sort4 pero haciendo rra 2 veces cuando len sea 3 y en 4 un solo rra

	if (check_sort(stack_a))
		return ;
	len = distance(stack_a, get_min_val(stack_a, -1));
	if (len == 1)
		ra(stack_a);
	else if (len == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (len == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (len == 4)
		rra(stack_a);
	pa(stack_a, stack_b);
	sort4(stack_a, stack_b);
	pb(stack_a, stack_b);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size; // El tamaño de nodos a guardar para el sort

	if (check_sort(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_b) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort3(stack_a);
	else if (size == 4)
		sort4(stack_a, stack_b);
	else if (size == 5)
		sort5(stack_a, stack_b);
}