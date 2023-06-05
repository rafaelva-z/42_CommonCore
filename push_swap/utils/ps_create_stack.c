/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:25:32 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/05 15:28:17 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*create_stack(char **argv, int argc)
{
	t_list	*stack_a;
	t_list	*node;

	stack_a = ft_lstnew(ft_atoi(argv[--argc]));
	while (--argc > 0)
	{
		node = ft_lstnew(ft_atoi(argv[argc]));
		ft_lstadd_front(&stack_a, node);
	}
	return (stack_a);
}

t_list	*create_stack_int(int *seq, int argc)
{
	t_list	*stack_a;
	t_list	*node;

	argc--;
	stack_a = ft_lstnew(seq[--argc]);
	while (--argc >= 0)
	{
		node = ft_lstnew(seq[argc]);
		ft_lstadd_front(&stack_a, node);
	}
	return (stack_a);
}
