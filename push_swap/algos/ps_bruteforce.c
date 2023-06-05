/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bruteforce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:21:00 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/05 15:28:46 by rvaz             ###   ########.fr       */
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

static void	calc_solve(int **s, int i)
{
	int	k;
	int	j;

	k = 1;
	j = 1;
	if (i > 0)
	{
		while (j++ < i)
		{
			if (((*s)[j] == (*s)[k] && ((*s)[j] == 1 || (*s)[j] == 2
			|| (*s)[j] == 3)) || ((*s)[j] == (*s)[k] - 1 && ((*s)[j] == 1 ||
			(*s)[j] == 4 || (*s)[j] == 7 || (*s)[j] == 10)) ||
			((*s)[j] == (*s)[k++] + 1 && ((*s)[j] == 2 || (*s)[j] == 5 ||
			(*s)[j] == 8 || (*s)[j] == 11)))
			{
				(*s)[j]++;
				return ;
			}
		}
		if ((*s)[i]++ < 11)
			return ;
		(*s)[i--] = 1;
		calc_solve(s, i);
	}
}

static void	operations(t_list **stack_a, t_list **stack_b, int **solve, int i)
{
	while (--i >= 1)
	{	
		if ((*solve)[i] == 1 && *stack_a)
			sa(stack_a, (*solve)[0]);
		else if ((*solve)[i] == 2 && *stack_b)
			sb(stack_b, (*solve)[0]);
		else if ((*solve)[i] == 3 && *stack_a && *stack_b)
			ss(stack_a, stack_b, (*solve)[0]);
		else if ((*solve)[i] == 4 && *stack_a)
			ra(stack_a, (*solve)[0]);
		else if ((*solve)[i] == 5 && *stack_b)
			rb(stack_b, (*solve)[0]);
		else if ((*solve)[i] == 6 && *stack_a && *stack_b)
			rr(stack_a, stack_b, (*solve)[0]);
		else if ((*solve)[i] == 7 && *stack_a)
			rra(stack_a, (*solve)[0]);
		else if ((*solve)[i] == 8 && *stack_b)
			rrb(stack_b, (*solve)[0]);
		else if ((*solve)[i] == 9 && *stack_a && *stack_b)
			rrr(stack_a, stack_b, (*solve)[0]);
		else if ((*solve)[i] == 10 && *stack_b)
			pa(stack_a, stack_b, (*solve)[0]);
		else if ((*solve)[i] == 11 && *stack_a)
			pb(stack_a, stack_b, (*solve)[0]);
	}
}

static void	reduplicate_stacks(
	t_list **stack_a, t_list **stack_b, t_list **stack_ab, t_list **stack_bb)
{
	free_stacks(stack_a, stack_b);
	*stack_a = ft_lstdup(*stack_ab);
	*stack_b = ft_lstdup(*stack_bb);
}

void	ps_bruteforce(t_list **stack_a, t_list **stack_b)
{
	int		*solve;
	int		i;
	int		solve_positions;
	t_list	*stack_ab;
	t_list	*stack_bb;

	stack_ab = ft_lstdup(*stack_a);
	stack_bb = ft_lstdup(*stack_b);
	solve_positions = 9;
	solve = calloc(sizeof(int), (solve_positions--));
	i = solve_positions + 1;
	solve[i] = 1;
	while (!ps_solve_checker(*stack_a, *stack_b) && solve[0] == 0)
	{
		reduplicate_stacks(stack_a, stack_b, &stack_ab, &stack_bb);
		operations(stack_a, stack_b, &solve, i);
		i = solve_positions + 1;
		if (!ps_solve_checker(*stack_a, *stack_b))
			calc_solve(&solve, i);
	}
	reduplicate_stacks(stack_a, stack_b, &stack_ab, &stack_bb);
	solve[0] = 1;
	operations(stack_a, stack_b, &solve, i);
	free_stacks(&stack_ab, &stack_bb);
	free(solve);
}

/*---------------------------------------------------------*/
/*

static	void	perform_bf(t_list **stack_a, t_list **stack_b, int **solve)
{
	int		i;
	t_list	*stack_ab;
	t_list	*stack_bb;

	stack_ab = ft_lstdup(*stack_a);
	stack_bb = ft_lstdup(*stack_b);
	i = 14;
	while (i >= 1 && solve[i] != 0)
		operations(&stack_ab, &stack_bb, solve, i--);
	i = 14;
	if (!ps_solve_checker(stack_ab, stack_bb) && (*solve)[0] == 0)
	{
		//print_stacks(stack_ab, stack_bb);
		ft_lstclear(&stack_ab, ft_bzero_int);
		ft_lstclear(&stack_bb, ft_bzero_int);
		//print_solve(solve, i);
		calc_solve(solve, i);
		perform_bf(stack_a, stack_b, solve);
	}
	ft_lstclear(&stack_ab, ft_bzero_int);
	ft_lstclear(&stack_bb, ft_bzero_int);
	// else
	// {
	// 	if (solve[0] == 0)
	// 	{
	// 		solve[0] = 1;
	// 		perform_bf(stack_a, stack_b, solve);
	// 	}
	// }
}

void	ps_bruteforce(t_list **stack_a, t_list **stack_b)
{
	int	*solve;

	solve = calloc(sizeof(int), 15);
	perform_bf(stack_a, stack_b, &solve);
	printf("welp bf\n");
	free(solve);
}*/