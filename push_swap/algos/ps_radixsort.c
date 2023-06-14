/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radixsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:41:21 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/14 18:11:33 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	lst_biggestval(t_list *lst)
{
	int	maxnum;

	maxnum = INT_MIN;
	while (lst)
	{
		if (lst->nb > maxnum)
		maxnum = lst->nb;
		lst = lst->next;
	}
	return (maxnum);
}

static void	*normalize_seq(t_list **stack_a, int size)
{
	int		*norm_seq;
	t_list	*tmp;
	int		i;
	int		j;
	int		tmpnum;

	norm_seq = calloc(sizeof(int), size);
	if (!norm_seq)
		return (NULL);
	tmp = *stack_a;
	i = -1;
	while (tmp && i < size)
	{
		norm_seq[++i] = tmp->nb;
		tmp = tmp->next;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
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
	tmp = *stack_a;
	while (tmp)
	{
		i = -1;
		while (norm_seq[++i])
		{
			if (tmp->nb == norm_seq[i])
			{
				tmp->nb = i;
				break ;
			}
		}
		tmp = tmp->next;
	}
}

void	ps_radixsort(t_list **stack_a, t_list **stack_b)
{
	int	lst_size;
	int	biggest_num;
	int	most_bits;
	int	i;
	int	j;

	lst_size = ft_lstsize(*stack_a);
	normalize_seq(stack_a, lst_size);
	biggest_num = lst_size - 1;
	most_bits = 0; 
	while (biggest_num >> most_bits != 0)
		most_bits++;
	i = 0;
	while (i < most_bits)
	{
		j = 0;
		while (j < lst_size)
		{
			if (((*stack_a)->nb >> i) & 1 == 1)
				ra(stack_a, 1);
			else
				pb(stack_a, stack_b, 1);
			j++;
		}
		print_stacks(*stack_a, *stack_b);
		while (*stack_b)
			pa(stack_a, stack_b, 1);
		i++;
	}
}
/* BINARY TABLE
0 = 0000
1 = 0001
2 = 0010
3 = 0011
4 = 0100
5 = 0101
6 = 0110
7 = 0111
8 = 1000
9 = 1001
*/