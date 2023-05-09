/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:25:43 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/09 19:00:53 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error(void)
{
	printf("ERROR\n\n");
}

int main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if(argc)
	{
		
	}
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_error();
				return (0);
			}
		}
		printf("number: %d\n", ft_atoi(argv[i]));
	}
	printf("Nuthin");
}