/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_newsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:23:01 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/31 17:25:52 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
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
}*/

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

int	best_num(t_list stack_a, t_list *stack_b)
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
	tmp = *stack_a;

	while (tmp && tmp->nb != nb)
	{
		a_moves++;
		tmp = tmp->next;
	}
	if (a_moves >= (ft_lstsize(*stack_a) / 2))
		a_moves = (ft_lstsize(*stack_a) - a_moves) * -1;
	bestnum = best_num(*tmp, *stack_b);
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
	tmp = *stack_b;

	while (tmp && tmp->nb != nb)
	{
		b_moves++;
		tmp = tmp->next;
	}
	if (b_moves >= (ft_lstsize(*stack_b) / 2) && b_moves)
		b_moves = (ft_lstsize(*stack_b) - b_moves) * -1;
	bestnum = best_num(*tmp, *stack_a);
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

/* static t_list *find_biggest_seq(t_list *stack)
{
	t_list *tmp;
	t_list *return_list;
	int counter;
	int last_nb;

	counter = 0;
	last_nb = INT_MIN;
	return_list = ft_lstnew();
	while ()
	{
		tmp = stack;
		while (tmp)
		{
			if(tmp->nb > last_nb)
				
			tmp = tmp->next;
		}
	}
} */

void	ps_newsort(t_list **stack_a, t_list **stack_b)
{
	t_list	*aaa;
	// t_list	*seq;

	aaa = NULL;
	// seq = find_biggest_seq(*stack_a);

	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	if ((*stack_b)->nb < (*stack_b)->next->nb)
		sb(stack_b, 1);
// print_stacks(*stack_a, *stack_b);
	while (ft_lstsize(*stack_a) > 3)
		pb_desc(stack_a, stack_b, find_cheapest(*stack_a, *stack_b));
// print_stacks(*stack_a, *stack_b);
	if (!ps_solve_checker(*stack_a, *stack_b) && *stack_a)
		ps_bruteforce(stack_a, &aaa);
// print_stacks(*stack_a, *stack_b);
	rb_totop(stack_b, lst_biggest_nb_pos(*stack_b));
	while (ft_lstsize(*stack_b))
		pa_asc(stack_b, stack_a, find_cheapest(*stack_b, *stack_a));
	ra_totop(stack_a, lst_smallest_nb_pos(*stack_a));
// print_stacks(*stack_a, *stack_b);
}