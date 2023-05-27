/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_newsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:23:01 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/27 16:32:12 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*normalize_seq(t_list **stack_a, int num_size)
{
	int		*norm_seq;
	t_list	*tmp;
	int		i;

	norm_seq = calloc(sizeof(int), num_size);
	if (!norm_seq)
		return (NULL);
	tmp = *stack_a;
	i = -1;
	while (tmp && i < num_size)
	{
		norm_seq[++i] = tmp->nb;
		tmp = tmp->next;
	}

	int	j;
	int	tmpnum;
	i = 0;
	while (i < num_size)
	{
		j = i + 1;
		while (j < num_size)
		{
			if (norm_seq[i] > norm_seq[j])
			{
				tmpnum = norm_seq[j];
				norm_seq[j] = norm_seq[i];
				norm_seq[i] = tmpnum; 
			}
			j++;
		}
		i++;
	}
	return (norm_seq);
}

static int	lst_maxint(t_list *stack)
{
	int	max;

	max = 0;
	while (stack)
	{
		if (stack->nb > max)
			max = stack->nb;
		stack = stack->next;
	}
	return (max);
}

static int	best_num(t_list stack_a, t_list *stack_b)
{
	int		bestnum;
	t_list	*tmp;
	int		flag;

	flag = 0;
	bestnum = INT_MIN;
	tmp = stack_b;
	while (tmp)
	{
		if (tmp->nb >= bestnum && tmp->nb < stack_a.nb)
		{
			bestnum = tmp->nb;
			flag = 1;
		}
		tmp = tmp->next;
	}
	if (!flag)
	{
		bestnum = INT_MAX;
		tmp = stack_b;
		while (tmp)
		{
			if (tmp->nb < bestnum && tmp->nb > stack_a.nb)
				bestnum = tmp->nb;
			tmp = tmp->next;
		}
	}
	return (bestnum);
}


static int calculate_cost(t_list stack_a, int stack_a_size, int *moves, int *return_value)
{
	int			cost;
	static int	best_cost;

	if (moves[0] > stack_a_size / 2)
		cost = stack_a_size - moves[0] + moves[1] + 1;
	else
		cost = moves[0] + moves[1] + 1;
	if (cost < best_cost || !*return_value)
	{
		*return_value = stack_a.nb;
		best_cost = cost;
	}
	//printf("Stack_a: %d, COST: %d\n", stack_a.nb, cost);
}

static int calculate_moves(t_list *stack_a, t_list *stack_b, int *moves_1)
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

static void	rotate_stacks(
	t_list **stack_a, t_list **stack_b, int a_moves, int b_moves)
{
	while (a_moves != 0 || b_moves != 0)
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
			if (a_moves > 0)
			{
				ra(stack_a, 1);
				a_moves--;
			}
			else if (a_moves < 0)
			{
				rra(stack_a, 1);
				a_moves++;
			}
			if (b_moves > 0)
			{
				rb(stack_b, 1);
				b_moves--;
			}
			else if(b_moves < 0)
			{
				rrb(stack_b, 1);
				b_moves++;
			}
		}
	}
}

static void organized_pb(t_list **stack_a, t_list **stack_b, int nb)
{
	int		bestnum;
	int		a_moves;
	int		b_moves;
	int		stack_a_size;
	t_list	*tmp;

	a_moves = 0;
	b_moves = 0;
	stack_a_size = ft_lstsize(*stack_a);
	tmp = *stack_a;

	while (tmp->nb != nb && tmp)
	{
		a_moves++;
		tmp = tmp->next;
	}
		bestnum = best_num(*tmp, *stack_b);
	if (a_moves >= (ft_lstsize(*stack_a) / 2))
		a_moves = (ft_lstsize(*stack_a) - a_moves) * -1;
	tmp = *stack_b;
	while (tmp->nb != bestnum && tmp)
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

static	int lst_biggest_nb_pos(t_list *stack)
{
	int		biggest_nb;
	int		count;
	int		tmp_count;

	tmp_count = 0;
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


void	r_bigtotop(t_list **stack)
{
	int		count;

	count = lst_biggest_nb_pos(*stack);
	if (count >= ft_lstsize(*stack) / 2)
		count = (ft_lstsize(*stack) - count) * -1;
	while (count != 0)
	{
		if (count > 0)
		{
			rb(stack, 1);
			count--;
		}
		else if (count < 0)
		{
			rrb(stack, 1);
			count++;
		}
	}
}


void	ps_newsort(t_list **stack_a, t_list **stack_b, int num_size)
{
	int		*norm_seq;
	t_list	*stack_bb;

	stack_bb = NULL;
	norm_seq = normalize_seq(stack_a, num_size);
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	if ((*stack_b)->nb < (*stack_b)->next->nb)
		sb(stack_b, 1);
	while (ft_lstsize(*stack_a) > 3)
	{
		//print_stacks(*stack_a, *stack_b);
		organized_pb(stack_a, stack_b, find_cheapest(*stack_a, *stack_b));
	}
	ps_bruteforce(stack_a, &stack_bb);
	r_bigtotop(stack_b);
// PUSH BACK TO A
	ft_bzero_int(norm_seq);
	free(norm_seq);
	printf("\nwelp\n\n");
}