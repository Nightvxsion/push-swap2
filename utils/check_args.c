/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgar2 <marcgar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:56:05 by marcgar2          #+#    #+#             */
/*   Updated: 2024/12/26 23:56:05 by marcgar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

/*static int	args_coincidence(int num, char **argv, int i)
{
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num) // Si coincide un numero
			return (1);
		i++;
	}
	return (0);
}*/

static int args_is_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_all_args(int argc, char **argv)
{
	int		i;
	char	**arguments;
	long	tmp; // Long para manejar el caso de INT_MIN/INT_MAX
	
	i = 0;
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		arguments = argv;
	}
	while (arguments[i])
	{
		tmp = ft_atoi(arguments[i]);
		if (!args_is_num(arguments[i]))
			ft_err("ERR 01 -> Is not a number, dumbass");
		//if (args_coincidence(tmp, arguments, i))
			//ft_err("ERR 02 -> Already exists a number");
		if (tmp < -2147483648)
			ft_err("ERR 03 -> INT_MIN careful!");
		if (tmp > 2147483648)
			ft_err("ERR 04 -> INT_MAX careful!");
		i++;
	}
	if (argc == 2)
		ft_free(arguments);
}