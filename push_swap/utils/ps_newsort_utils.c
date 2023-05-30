/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_newsort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:41:21 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/30 17:39:21 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	calculate_cost(
	t_list stack, int stack_size, int *moves, int *return_value)
{
	int			cost;
	static int	best_cost;

	if (moves[0] > stack_size / 2)
		cost = stack_size - moves[0] + moves[1] + 1;
	else
		cost = moves[0] + moves[1] + 1;
	if (cost < best_cost || !*return_value)
	{
		*return_value = stack.nb;
		best_cost = cost;
	}
}

static void	calculate_moves(t_list *stack_a, t_list *stack_b, int *moves_1)
{
	int		bestnum;
	int		stack_b_size;

	stack_b_size = ft_lstsize(stack_b);
	bestnum = best_num(*stack_a, stack_b);
	while (stack_b && stack_b->nb != bestnum)
	{
			(*moves_1)++;
			stack_b = stack_b->next;
	}
	if ((*stack_a).nb > bestnum && *moves_1 >= (stack_b_size / 2))
		*moves_1 = stack_b_size - *moves_1;
	else if ((*stack_a).nb < bestnum && *moves_1 >= (stack_b_size / 2))
		*moves_1 = stack_b_size - *moves_1 - 1;
	else if ((*stack_a).nb < bestnum && *moves_1 < (stack_b_size / 2))
		*moves_1++;
}

//Need to optizmize when ra + rb to rotate both on one move
int	find_cheapest(t_list *stack_a, t_list *stack_b)
{
	int		moves[2];
	int		return_value;
	int		stack_a_size;

	stack_a_size = ft_lstsize(stack_a);
	return_value = 0;
	moves[0] = 0;
	while (stack_a)
	{
		moves[1] = 0;
		calculate_moves(stack_a, stack_b, &moves[1]);
		calculate_cost(*stack_a, stack_a_size, moves, &return_value);
		moves[0]++;
		stack_a = stack_a->next;
	}
	return (return_value);
}

int	lst_biggest_nb_pos(t_list *stack)
{
	int		biggest_nb;
	int		count;
	int		tmp_count;

	tmp_count = 0;
	count = 0;
	biggest_nb = stack->nb;
	while (stack)
	{
		if (stack->nb > biggest_nb)
		{
			biggest_nb = stack->nb;
			count = tmp_count;
		}
		tmp_count++;
		stack = stack->next;
	}
	return (count);
}

int	lst_smallest_nb_pos(t_list *stack)
{
	int		smallest_nb;
	int		count;
	int		tmp_count;

	tmp_count = 0;
	count = 0;
	smallest_nb = stack->nb;
	while (stack)
	{
		if (stack->nb < smallest_nb)
		{
			smallest_nb = stack->nb;
			count = tmp_count;
		}
		tmp_count++;
		stack = stack->next;
	}
	return (count);
}
