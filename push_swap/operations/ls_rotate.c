/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:36:02 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/11 14:19:38 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*tmp;

	if ((*stack)->next)
	{
	tmp = (*stack)->next;
	ft_lstadd_back(stack, *stack);
	(*stack)->next = NULL;
	*stack = tmp;
	}
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	// ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	// ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	// ft_printf("rr\n");
}
