/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_totop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:19:25 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/30 16:19:34 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb_totop(t_list **stack_b, int nb_pos)
{
	if (nb_pos >= ft_lstsize(*stack_b) / 2)
		nb_pos = (ft_lstsize(*stack_b) - nb_pos) * -1;
	while (nb_pos != 0)
	{
		if (nb_pos > 0)
		{
			rb(stack_b, 1);
			nb_pos--;
		}
		else if (nb_pos < 0)
		{
			rrb(stack_b, 1);
			nb_pos++;
		}
	}
}

void	ra_totop(t_list **stack_a, int nb_pos)
{
	if (nb_pos >= ft_lstsize(*stack_a) / 2)
		nb_pos = (ft_lstsize(*stack_a) - nb_pos) * -1;
	while (nb_pos != 0)
	{
		if (nb_pos > 0)
		{
			ra(stack_a, 1);
			nb_pos--;
		}
		else if (nb_pos < 0)
		{
			rra(stack_a, 1);
			nb_pos++;
		}
	}
}