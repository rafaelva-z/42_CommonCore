/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:26:20 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/30 16:17:40 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a, ft_bzero_int);
	ft_lstclear(stack_b, ft_bzero_int);
}
