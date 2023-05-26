/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_newsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:23:01 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/26 16:10:51 by rvaz             ###   ########.fr       */
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
		if (!(tmp->next))
			break ;
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

int	find_cheapest(t_list *stack_a, t_list *stack_b)
{
	int		bestnum;
	int		cost;
	int		a_moves;
	int		b_moves;
	t_list	*tmp;
	int		stack_a_size;
	int		return_value;

	return_value = 0;
	a_moves = 0;
	stack_a_size = ft_lstsize(stack_a);
	while (stack_a)
	{
		b_moves = 0;
		tmp = stack_b;
		bestnum = best_num(*stack_a, stack_b);
		
// CALCULATE B_MOVES

		if (stack_a->nb > bestnum)
		{
			while (tmp->nb != bestnum && tmp)
			{
				b_moves++;
				tmp = tmp->next;
			}
			if (b_moves <= (ft_lstsize(stack_b) / 2))
				cost = b_moves;
			else
			{
				b_moves = 0;
				while (tmp)
				{
					b_moves++;
					tmp = tmp->next;
				}
			}
		}
		else
		{
			while (tmp->nb != bestnum && tmp)
			{
				b_moves++;
				tmp = tmp->next;
			}
			b_moves++;
			if (b_moves <= (ft_lstsize(stack_b) / 2))
				cost = b_moves;
			else
			{
				b_moves = 0;
				while (tmp->next)
				{
					b_moves++;
					tmp = tmp->next;
				}
			}
		}
// CALCULATE COST
		if (stack_a->nb > bestnum)
		{
			if (a_moves > stack_a_size / 2)
				cost = stack_a_size - a_moves + b_moves + 1;
			else
				cost = a_moves + b_moves + 1;
		}
		else
		{
			if (a_moves > stack_a_size / 2)
				cost = stack_a_size - a_moves + b_moves + 1;
			else
				cost = a_moves + b_moves + 1;
		}
//
		if (cost < return_value || !return_value)
			return_value = stack_a->nb;
		printf("NUM STACKA: %d, bestnum: %d, COST: %d\n", stack_a->nb, bestnum, cost);
		a_moves++;
		stack_a = stack_a->next;
	}
	return (return_value);
}

static void organized_pb(t_list *stack_a, t_list *stack_b, int positon)
{
	

}

void	ps_newsort(t_list **stack_a, t_list **stack_b, int num_size)
{
	int	*norm_seq;
	norm_seq = normalize_seq(stack_a, num_size);
	print_stacks(*stack_a, *stack_b);

// FIRST OPERATIONS
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	if((*stack_b)->nb < (*stack_b)->next->nb)
		sb(stack_b, 1);
	print_stacks(*stack_a, *stack_b);
// ACTUAL ALGO
	while (ft_lstsize(*stack_a) > 3)
	{
		organized_pb(*stack_a, *stack_b, find_cheapest(*stack_a, *stack_b));
		pb(stack_a, stack_b, 1);


		print_stacks(*stack_a, *stack_b);
	}
// BRUTE FORCE LAST NUMBERS IN A
	//ps_bruteforce(stack_a, NULL);
// PUSH BACK TO A


// FREE THE MEMORY
	ft_bzero_int(norm_seq);
	free(norm_seq);
	printf("\nwelp\n\n");
}