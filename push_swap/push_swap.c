/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:25:43 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/09 16:13:27 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *seq, int seq_size)
{
	stack	tack_a;
	stack	*stack_b;

	
}

int main(int argc, char **argv)
{
	int	i;
	int j;

	i = 0;
	j = -1;
	while (argv[++i])
	{
		while (argv[i][++j])
		{
			if (ft_isdigit(argv[i][j]))
			{
				printf("sizeof: %lu\n", sizeof(argv[i]));
			}


		}
	}
	printf("Nuthin");
}