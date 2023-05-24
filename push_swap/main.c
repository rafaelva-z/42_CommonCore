/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:25:43 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/24 12:11:41 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(int argc, char **argv, t_list **stack_a, t_list **stack_b)
{
	if (ps_checker(*stack_a, *stack_b))
		return ;
	if (argc <= 5)
		ps_bruteforce(stack_a, stack_b);
	else if (argc < 1000)
	{
		printf("b\n");
		ps_newsort(stack_a, stack_b, argc - 1);
	}
	//HEAPERMUTATIONS
	/* int a[] = {2, 1, 3, 4, 5};
	int n = sizeof a / sizeof a[0];
	heapperm(a, n, n, &stack_a, &stack_b, argc);
	//print_stacks(stack_a, stack_b); */
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = create_stack(argv, argc);
	stack_b = NULL;

	printf("%d\n", argc);

	if (argc <= 1)
		return (0);
	if (!ps_input_checker(argv))
		return (ft_error());
	push_swap(argc, argv, &stack_a, &stack_b);

	ft_lstclear(&stack_a, ft_bzero_int);
	ft_lstclear(&stack_b, ft_bzero_int);
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