/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:25:33 by marcgar2          #+#    #+#             */
/*   Updated: 2024/12/17 20:25:33 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_list
{
	int	value;
	int	index;
	struct s_list	*next;
} t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_putnbr_fd(int n, int fd);
void	printlist(t_list *lst);
void	ft_putendl_fd(char *s, int fd);
void	ft_err(char *error);
void	ft_free(char **str);
int		check_sort(t_list **lst);
void	free_stack(t_list **stack);
int		swap(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		push(t_list **stack_src, t_list **stack_dst);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
int		rotate(t_list **stack);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		reverseRotate(t_list **stack);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);
int		distance(t_list **stack);
void	sort3(t_list **stack);
void	simple_sort(t_list **stack_a, t_list **stack_b);
//void	radix(t_list **stack_a, t_list **stack_b);
void	move_a_to_b(t_list **stack_a, t_list **stack_b, int max, int min);
void	move_b_to_a(t_list **stack_a, t_list **stack_b);
void	k_sort(t_list **stack_a, t_list **stack_b, int k);
void	index_of_stack(t_list **stack_a);
void	check_all_args(int argc, char **argv);
void	insertion_sort(t_list **stack_a, t_list **stack_b);
int		get_min_val(t_list **stack, int val);

#endif