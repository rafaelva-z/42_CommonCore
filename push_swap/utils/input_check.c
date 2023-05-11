/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:19:08 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/11 00:30:00 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//one extra line..
int	input_check(char **input)
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
		{
			if (!ft_isdigit(input[i][j]))
				return (0);
		}
		this_nb = ft_atoi(input[i]);
		if (this_nb > INT_MAX || this_nb < INT_MIN)
			return (0);
		j = i;
		while (j > 1)
		{
			if (ft_atoi(input[--j]) == this_nb)
				return (0);
		}
	}
	return (1);
}
