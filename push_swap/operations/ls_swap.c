/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:36:05 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/11 14:19:37 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*tmp;

	if ((*stack)->next)
	{
	tmp = (*stack)->next->next;
	ft_lstadd_front(stack, (*stack)->next);
	(*stack)->next->next = tmp;
	}
	return ;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	// ft_printf("sa\n");
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	// ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	// ft_printf("ss\n");
}
