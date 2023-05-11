/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:25:43 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/11 00:48:56 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stacks(t_list *stack_a, t_list *stack_b)
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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	if (!input_check(argv))
		return (ft_error());
	stack_a = create_stack(argv, argc);
	print_stacks(stack_a, stack_b);
	sa(&stack_a);
	ft_printf("Solve state: %d\n", solve_check(stack_a, stack_b));
}

/*
//OPERATIONS
swap
sa(&stack_a);
sb(&stack_b);
ss(&stack_a, &stack_b);

rotate
ra(&stack_a);
rb(&stack_b);
rs(&stack_a, &stack_b);

rev rotate
rra(&stack_a);
rrb(&stack_b);
rrs(&stack_a, &stack_b);

push
pa(&stack_a, &stack_b);
pb(&stack_a, &stack_b);
*/