/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:23:48 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/12 12:52:49 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	ft_printf("\n=====PushSwap=====\n");
	ft_printf("stack A\t stack B\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%d", stack_a->nb);
			stack_a = stack_a->next;
		}
		ft_printf("\t|\t");
		if (stack_b)
		{
			ft_printf("%d", stack_b->nb);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("=============rvaz=\n\n");
}
