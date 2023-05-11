/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:21:00 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/11 17:13:00 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static t_list	**reset_stack(t_list **stack, t_list *stack_backup)
// {
// 	t_list *reset_stack;

// 	reset_stack = ft_lstmap(stack_backup);
// 	stack = &reset_stack;
// 	return (stack);
// }

static void print_solve(int *solve, int argc)
{
	int i;
	int j;
	int k;

	i = 0;
	j = argc;
	k = 0;
	while (j > 0)
	{
		if (solve[j--] > 0)
			k++;
	}

	if (k > 8)
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

static void calc_solve(int **solve, int i)
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

t_list	*create_stack(char **argv, int argc)
{
	t_list	*stack_a;
	t_list	*node;

	stack_a = ft_lstnew(ft_atoi(argv[--argc]));
	while (--argc > 0)
	{
		node = ft_lstnew(ft_atoi(argv[argc]));
		ft_lstadd_front(&stack_a, node);
	}
	return (stack_a);
}

t_list	*create_stack_int(int *seq, int argc)
{
	t_list	*stack_a;
	t_list	*node;

	argc--;
	stack_a = ft_lstnew(seq[--argc]);
	while (--argc >= 0)
	{
		node = ft_lstnew(seq[argc]);
		ft_lstadd_front(&stack_a, node);
	}
	return (stack_a);
}

int	solve_check(t_list *stack_a, t_list *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->nb > stack_a->next->nb)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

// int	move_condition()
// {

// }

void brute_solver(t_list **stack_a, t_list **stack_b, int argc)
{
	int	*solve;
	int i;
	int try;

	argc = 100;

	solve = calloc(sizeof(int), (argc--));

	t_list *stack_ab = NULL;
	t_list *stack_bb = NULL;

	stack_ab = ft_lstmap(*stack_a);
	stack_bb = ft_lstmap(*stack_b);

	try = 0;

	i = argc;
	solve[i] = 1;
	while (!solve_check(*stack_a, *stack_b) && solve[0] == 0)
	{
		ft_lstclear(stack_a, ft_bzero_int);
		ft_lstclear(stack_b, ft_bzero_int);
		*stack_a = ft_lstmap(stack_ab);
		*stack_b = ft_lstmap(stack_bb);
		while (i >= 1 && solve[i] != 0)
		{
			//ft_printf("Try number: %d, i = %d, solve[i] = %d\n", ++try, i, solve[i]);
			if (solve[i] == 1 && *stack_a)
				sa(stack_a);
			else if (solve[i] == 2 && *stack_b)
				sb(stack_b);
			else if (solve[i] == 3 && *stack_a && *stack_b)
				ss(stack_a, stack_b);
			else if (solve[i] == 4 && *stack_a)
				ra(stack_a);
			else if (solve[i] == 5 && *stack_b)
				rb(stack_b);
			else if (solve[i] == 6 && *stack_a && *stack_b)
				rr(stack_a, stack_b);
			else if (solve[i] == 7 && *stack_a)
				rra(stack_a);
			else if (solve[i] == 8 && *stack_b)
				rrb(stack_b);
			else if (solve[i] == 9 && *stack_a && *stack_b)
				rrr(stack_a, stack_b);
			else if (solve[i] == 10 && *stack_b)
				pa(stack_a, stack_b);
			else if (solve[i] == 11 && *stack_a)
				pb(stack_a, stack_b);
			i--;
		}
		i = argc;
		calc_solve(&solve, i);
		//print_stacks(*stack_a, *stack_b);
	}
	//print_stacks(*stack_a, *stack_b);
	print_solve(solve, argc);
}
