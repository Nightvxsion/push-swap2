/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:52:39 by marcgar2          #+#    #+#             */
/*   Updated: 2025/01/08 09:08:27 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_err(char *error)
{
	ft_putendl_fd(error, 1);
	exit(1);
}

void	ft_free(char **str)
{
	int	i;
	i = 0;

	if (!str)
		return ;
	while (str[i])
		i++;
	while (--i >= 0) // Se pone --i para evitar llegar a str[-1] lo cual no es cierto
		free(str[i]);
	free(str);
}

int	check_sort(t_list **lst)
{
	t_list	*head;

	head = *lst;
	while (head && head->next) // Mientras exista una lista y su siguiente
	{
		if (head->index > head->next->index) // Si el siguiente elemento es mayor que el anterior
			return (0); // return 0 por que no está ordenado
		head = head->next; // Avanzar a la siguiente posicion
	}
	return (1); // return 1 por que esta ordenado
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*temp;

	head = *stack;
	while (head)
	{
		temp = head; // Guardamos el stack en tmp
		head = head->next; // Avanzamos al siguiente nodo
		free(temp); // Liberamos el nodo actual
	}
	free(stack); // Liberamos EL PUNTERO de la direccion del stack
}

int	distance(t_list **stack)
{
	t_list	*head;
	int		distance;
	int		min_val;

	distance = 0;
	head = *stack;
	min_val = get_min_val(stack, -1); // Consigue el indice minimo
	while (head)
	{
		if (head->index == min_val)
			return (distance);
		distance++;
		head = head->next; // Recorrer el stack nodo a nodo
	}
	return (distance);
}

void	make_top(t_list **stack, int distance)
{
	t_list	*tmp;
	int		leng;

	tmp = *stack;
	leng = ft_lstsize(tmp) - leng;
	if (leng <= (ft_lstsize(tmp) / 2))
	{
		while(leng-- > 0)
			ra(stack);
	}
	else
	{
		while(tmp-- > 0)
			rra(stack);
	}
}