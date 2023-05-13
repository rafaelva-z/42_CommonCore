/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapperm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:31:09 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/13 21:36:19 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	heapperm(int *a, int size, int n, t_list **stack_a, t_list **stack_b,
		int argc)
{
	int tmp;
	int i;

	if (size == 1)
	{
		ft_lstclear(stack_a, ft_bzero_int);
		*stack_a = create_stack_int(a, argc);
		ps_bruteforce(stack_a, stack_b);
		return ;
	}
	i = -1;
	while (++i < size)
	{
		heapperm(a, size - 1, n, stack_a, stack_b, argc);
		if (size % 2 == 1)
			ft_swap(a, &a[size - 1], sizeof(int));
		else
			ft_swap(&a[i], &a[size - 1], sizeof(int));
	}
}