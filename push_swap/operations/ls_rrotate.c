/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:36:02 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/11 14:19:38 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rrotate(t_list **stack)
{
	t_list	*tmp;

	if ((*stack)->next)
	{
	tmp = ft_lstlast(*stack);
	ft_lstbeforelast(*stack)->next = NULL;
	ft_lstadd_front(stack, tmp);
	*stack = tmp;
	}
}

void	rra(t_list **stack_a)
{
	rrotate(stack_a);
	// ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	rrotate(stack_b);
	// ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	// ft_printf("rrr\n");
}
