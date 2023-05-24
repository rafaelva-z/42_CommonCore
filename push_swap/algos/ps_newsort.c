/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_newsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:23:01 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/24 13:22:38 by rvaz             ###   ########.fr       */
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
	int flag;

	flag = 0;
	bestnum = INT_MIN;
	tmp = stack_b;
	while (tmp)
	{
		if (stack_b->nb >= bestnum && stack_b->nb < stack_a.nb)
		{
			bestnum = stack_b->nb;
			flag = 1;
		}
		tmp = tmp->next;
	}
	if (flag != 0)
	{
		bestnum = INT_MAX;
		tmp = stack_b;
		while (tmp)
		{
			if (stack_b->nb < bestnum && stack_b->nb > stack_a.nb)
				bestnum = stack_b->nb;
			tmp = tmp->next;
		}
	}
	return (bestnum);
}

void	find_cheapest(t_list *stack_a, t_list *stack_b, int *norm_seq)
{
	int		bestnum;
	int		cost;
	int		count;
	int		a_moves;
	t_list	*tmp;

	a_moves = 0;
	count = 0;
	while (stack_a)
	{
		tmp = stack_b;
		bestnum = best_num(*stack_a, stack_b);
		while (tmp->nb != bestnum)
		{
			count++;
			tmp = tmp->next;
		}
		if (count < (ft_lstsize(stack_b) / 2))
		{
			cost = count;
		}
		else
		{
			count = 0;
			while (tmp)
			{
				count++;
				tmp = tmp->next;
			}
		}
		a_moves++;
		cost = a_moves + count + 1;
		if ()
		stack_a = stack_a->next;
	}

}

void	ps_newsort(t_list **stack_a, t_list **stack_b, int num_size)
{
	int	*norm_seq;
	norm_seq = normalize_seq(stack_a, num_size);
	print_stacks(*stack_a, *stack_b);
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	while (ft_lstsize(*stack_a) > 3)
	{
		find_cheapest(*stack_a, *stack_b, norm_seq);
		pb(stack_a, stack_b, 1);
		// if ((*stack_a)->nb > norm_seq[num_size / 2])
		// {
		// 	pb(stack_a, stack_b, 1);
		// }
		// else
		// {
		// 	pb(stack_a, stack_b, 1);
		// 	rb(stack_b, 1);
		// }
		// if (((*stack_b)->nb < (*stack_b)->next->nb))
		// 	sb(stack_b, 1);
		print_stacks(*stack_a, *stack_b);
	}
	//ps_bruteforce(stack_a, NULL);
	
	ft_bzero_int(norm_seq);
	free(norm_seq);
	printf("\nwelp\n\n");
}