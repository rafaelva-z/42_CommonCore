/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:25:43 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/10 19:35:57 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void print_stacks(t_list *stack_a, t_list *stack_b)
{
	ft_printf("=====PushSwap=====\n");
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
	ft_printf("=============rvaz=");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	//argc < 2 || <= 2 ??
	if (argc < 2 || !input_check(argv))
		return (ft_error());
	stack_a = create_stack(argv, argc);
	//sa(&stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	ss(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
}