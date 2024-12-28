/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:08:30 by marcgar2          #+#    #+#             */
/*   Updated: 2024/12/24 00:08:30 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_max_bits(t_list	**stack)
{
	t_list	*head;
	int		max;
	int		max_bit;

	head = *stack; // Referencia a la lista
	max = head->index; // Top de la lista
	max_bit = 0; // Bit maximo
	while (head)
	{
		if (head->index > max) // Si el top de la lista es mayor que max
			max = head->index; // Entonces ese valor va a ser el mayor que existe
		head = head->next; // Itera sobre la lista
	}
	while ((max >> max_bit) != 0) // Mientras que el desplazamiento del valor obtenido de max sea distinto de 0, va a incrementar ese valor
		max_bit++;
	return (max_bit); // Retornas el numero de bits necesarios para hallar el numero decimal (traducido del binario)
}

void	radix(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bit;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bit = get_max_bits(stack_a);
	while(i < max_bit)
	{
		j = 0;
		while(j < size) // Evalua desde la posicion actual de i el numero de nodos
		{
			if(((head_a->index >> i) & 1) == 1) // Si tenemos por ejemplo 5 = 101 con i = 1 entonces (5 >> 1) & 1 != 1 entonces rota, (i es el numero de bits en binario)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while(ft_lstsize(*stack_b) != 0) // Insertamos aristar guardadas
			pa(stack_a, stack_b);
		i++;
	}
}

