/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:25:43 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/10 12:22:30 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_error(void)
{
	printf("ERROR\n");
	return (0);
}

int	is_signal(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	input_check(char **input)
{
	int		i;
	int		j;
	long	this_nb;

	i = 0;
	while (input[++i])
	{
		j = -1;
		if (!is_signal(input[i][++j]) && !ft_isdigit(input[i][j]))
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

int	main(int argc, char **argv)
{

	if (argc < 2 || !input_check(argv))
		return (ft_error());
	printf("Hey");
	//create_stack(argv);
	// while (i < argc - 1)
	// 	printf("number: %d\t", seq[i++]);
}