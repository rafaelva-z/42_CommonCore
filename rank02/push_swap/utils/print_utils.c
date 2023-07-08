/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:23:48 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/16 19:08:41 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	ft_printf("\n=====PushSwap=====\n");
	ft_printf("stack A\t stack B\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%d", stack_a->nb);
			stack_a = stack_a->next;
		}
		ft_printf("\t|\t");
		if (stack_b)
		{
			ft_printf("%d", stack_b->nb);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("=============rvaz=\n\n");
}

/*Print bruteforce combination being tried*/
void	print_solve(int *solve, int argc)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = argc;
	k = 0;
	while (j > 0)
	{
		if (solve[j--] > 0)
			k++;
	}
	if (k > 0)
	{
		i = 1;
		ft_printf("|solve_comb = ");
		ft_printf("%d/", solve[0]);
		while (i < argc)
			ft_printf("%d.", solve[i++]);
		ft_printf("%d |\n", solve[i]);
		ft_printf("Solved in %d moves.\n", k);
	}
}
