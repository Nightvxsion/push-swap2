/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:52:39 by marcgar2          #+#    #+#             */
/*   Updated: 2024/12/17 20:52:39 by marcgar2         ###   ########.fr       */
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
		if (head->value > head->next->value) // Si el siguiente elemento es mayor que el anterior
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

int	distance(t_list **stack, int index)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next; // Recorrer el stack nodo a nodo
	}
	return (distance);
}