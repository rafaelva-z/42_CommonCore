/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_newsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:23:01 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/16 17:37:07 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_moves(t_list **stack, int *moves, char stack_name)
{
	if (*moves > 0 && stack_name == 'a')
	{
		ra(stack, 1);
		(*moves)--;
	}
	else if (*moves < 0 && stack_name == 'a')
	{
		rra(stack, 1);
		(*moves)++;
	}
	if (*moves > 0 && stack_name == 'b')
	{
		rb(stack, 1);
		(*moves)--;
	}
	else if (*moves < 0 && stack_name == 'b')
	{
		rrb(stack, 1);
		(*moves)++;
	}
}

static void	rotate_stacks(
	t_list **stack_a, t_list **stack_b, int a_moves, int b_moves)
{
	while (a_moves || b_moves)
	{
		if (a_moves > 0 && b_moves > 0)
		{
			rr(stack_a, stack_b, 1);
			a_moves--;
			b_moves--;
		}
		else if (a_moves < 0 && b_moves < 0)
		{
			rrr(stack_a, stack_b, 1);
			a_moves++;
			b_moves++;
		}
		else
		{
			if (a_moves)
				rotate_moves(stack_a, &a_moves, 'a');
			else if (b_moves)
				rotate_moves(stack_b, &b_moves, 'b');
		}
	}
}

static void	pb_desc(t_list **stack_a, t_list **stack_b, int nb)
{
	int		bestnum;
	int		a_moves;
	int		b_moves;
	int		stack_a_size;
	t_list	*tmp;

	a_moves = 0;
	b_moves = 0;
	stack_a_size = ft_lstsize(*stack_a);
	tmp = ps_newsort_moves(stack_a, nb, &a_moves);
	if (a_moves >= (ft_lstsize(*stack_a) / 2))
		a_moves = (ft_lstsize(*stack_a) - a_moves) * -1;
	bestnum = find_bestnum(*tmp, *stack_b);
	tmp = *stack_b;
	while (tmp && tmp->nb != bestnum)
	{
		b_moves++;
		tmp = tmp->next;
	}
	if (nb < bestnum)
		b_moves++;
	if (b_moves >= (ft_lstsize(*stack_b) / 2))
		b_moves = (ft_lstsize(*stack_b) - b_moves) * -1;
	rotate_stacks(stack_a, stack_b, a_moves, b_moves);
	pb(stack_a, stack_b, 1);
}

static void	pa_asc(t_list **stack_b, t_list **stack_a, int nb)
{
	int		bestnum;
	int		a_moves;
	int		b_moves;
	int		stack_b_size;
	t_list	*tmp;

	a_moves = 0;
	b_moves = 0;
	stack_b_size = ft_lstsize(*stack_b);
	tmp = ps_newsort_moves(stack_b, nb, &b_moves);
	if (b_moves >= (ft_lstsize(*stack_b) / 2) && b_moves)
		b_moves = (ft_lstsize(*stack_b) - b_moves) * -1;
	bestnum = find_bestnum(*tmp, *stack_a);
	tmp = *stack_a;
	while (tmp && tmp->nb != bestnum)
	{
		a_moves++;
		tmp = tmp->next;
	}
	if (nb > bestnum)
		a_moves++;
	if (a_moves >= (ft_lstsize(*stack_a) / 2))
		a_moves = (ft_lstsize(*stack_a) - a_moves) * -1;
	rotate_stacks(stack_a, stack_b, a_moves, b_moves);
	pa(stack_a, stack_b, 1);
}

void	ps_newsort(t_list **stack_a, t_list **stack_b)
{
	t_list	*dummy_stack;

	dummy_stack = NULL;
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	if ((*stack_b)->nb < (*stack_b)->next->nb)
		sb(stack_b, 1);
	while (ft_lstsize(*stack_a) > 3)
		pb_desc(stack_a, stack_b, find_cheapest(*stack_a, *stack_b));
	if (!ps_solve_checker(*stack_a, *stack_b) && *stack_a)
		ps_bruteforce(stack_a, &dummy_stack);
	rb_totop(stack_b, lst_biggest_nb_pos(*stack_b));
	while (ft_lstsize(*stack_b))
		pa_asc(stack_b, stack_a, find_cheapest(*stack_b, *stack_a));
	ra_totop(stack_a, lst_smallest_nb_pos(*stack_a));
}
