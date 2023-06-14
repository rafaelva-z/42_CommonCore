/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:23:20 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/14 20:25:09 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_organized
int	ps_solve_checker(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a || stack_b)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->nb > stack_a->next->nb)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	ps_input_checker(char **input)
{
	int		i;
	int		j;
	long	this_nb;

	i = 0;
	while (input[++i])
	{
		j = -1;
		if (!ft_issignal(input[i][++j]) && !ft_isdigit(input[i][j]))
			return (0);
		while (input[i][++j])
			if (!ft_isdigit(input[i][j]))
				return (0);
		if (!(input[i][j]) && ft_issignal(input[i][j - 1]))
			return (0);
		this_nb = ft_atoi(input[i]);
		if (this_nb > INT_MAX || this_nb < INT_MIN)
			return (0);
		j = i;
		while (j > 1)
			if (ft_atoi(input[--j]) == this_nb)
				return (0);
	}
	return (1);
}
