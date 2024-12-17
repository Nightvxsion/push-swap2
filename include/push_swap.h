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
#endif