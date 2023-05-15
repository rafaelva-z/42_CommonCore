/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bruteforce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:21:00 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/15 17:05:55 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_solve(int *solve, int argc)
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

static void	calc_solve(int **solve, int i)
{
	if (i > 0)
	{
		if ((*solve)[i] < 11)
		{
			(*solve)[i] = (*solve)[i] + 1;
			return ;
		}
		(*solve)[i--] = 1;
		calc_solve(solve, i);
	}
}

static void	operations(t_list **stack_a, t_list **stack_b, int *solve, int i)
{
	if (solve[i] == 1 && *stack_a)
		sa(stack_a, solve[0]);
	else if (solve[i] == 2 && *stack_b)
		sb(stack_b, solve[0]);
	else if (solve[i] == 3 && *stack_a && *stack_b)
		ss(stack_a, stack_b, solve[0]);
	else if (solve[i] == 4 && *stack_a)
		ra(stack_a, solve[0]);
	else if (solve[i] == 5 && *stack_b)
		rb(stack_b, solve[0]);
	else if (solve[i] == 6 && *stack_a && *stack_b)
		rr(stack_a, stack_b, solve[0]);
	else if (solve[i] == 7 && *stack_a)
		rra(stack_a, solve[0]);
	else if (solve[i] == 8 && *stack_b)
		rrb(stack_b, solve[0]);
	else if (solve[i] == 9 && *stack_a && *stack_b)
		rrr(stack_a, stack_b, solve[0]);
	else if (solve[i] == 10 && *stack_b)
		pa(stack_a, stack_b, solve[0]);
	else if (solve[i] == 11 && *stack_a)
		pb(stack_a, stack_b, solve[0]);
}

static	void	perform_bf(t_list **stack_a, t_list **stack_b, int **solve)
{
	int		i;
	t_list	*stack_ab;
	t_list	*stack_bb;

	stack_ab = ft_lstdup(*stack_a);
	stack_bb = ft_lstdup(*stack_b);
	i = 14;
/* 	for(int k = 14; k >= 0; k--)
			printf("s%d: %d||%d ", k, (*solve)[k], i); 
		printf("\n\n"); */
	while (i >= 1 && (*solve)[i] != 0)
		operations(&stack_ab, &stack_bb, *solve, i--);
													printf("a");
	i = 14;
														printf("b");
	if (!ps_checker(stack_ab, stack_bb) && (*solve)[0] == 0)
	{
															printf("c");
		print_solve(*solve, i);
		printf("\n");
		calc_solve(solve, i);
		//print_stacks(stack_ab, stack_bb);
		perform_bf(stack_a, stack_b, solve);
															printf("d");
	}
	else
	{
		if((*solve)[0] == 0)
		{
			(*solve)[0] = 1;
			perform_bf(stack_a, stack_b, solve);
		}
	}
	ft_lstclear(&stack_ab, ft_bzero_int);
	ft_lstclear(&stack_bb, ft_bzero_int);
}

void	ps_bruteforce(t_list **stack_a, t_list **stack_b)
{
	int	*solve;

	solve = calloc(sizeof(int), 15);
	solve[14] = 1;
	perform_bf(stack_a, stack_b, &solve);
	printf("welp\n");
}