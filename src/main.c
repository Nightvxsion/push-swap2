/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:21:05 by marcgar2          #+#    #+#             */
/*   Updated: 2024/12/26 23:21:05 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	init_of_stack(t_list **stack_a, int argc, char **argv)
{
	t_list	*tmp;
	char	**arguments;
	int		i;

	i = 0;
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		arguments = argv;
	}
	while(arguments[i])
	{
		tmp = ft_lstnew(ft_atoi(arguments[i])); // Los numeros que consiga de la conversion a int lo pasa a su vez a lstnew
		ft_lstadd_back(stack_a, tmp); // El nodo creado pasa al final para la colocacion
		i++; // Pasa al siguiente numero
	}
	index_of_stack(stack_a);
	if (argc == 2)
	{
		ft_free(arguments);
		free_stack(stack_a);
	}
}

static void	choose_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
	{
		ft_err("ERR 05 -> Less than 2 arguments, should be 2 or more!");
		return (-1);
	}
	check_all_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list)); 
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	init_of_stack(stack_a, argc, argv);
	if (check_sort(stack_a))
	{
		ft_err("WARNING -> Ya esta ordenado, gilipollas!");
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	choose_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
