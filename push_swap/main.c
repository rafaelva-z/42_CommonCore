/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:25:43 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/15 16:48:34 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = create_stack(argv, argc);
	stack_b = NULL;
	if (ps_checker(stack_a, stack_b))
		return ;
	if(argc < 7)
		ps_bruteforce(&stack_a, &stack_b);
	else if(argc < 100)
		ps_newsort(&stack_a, &stack_b, argc);
	//HEAPERMUTATIONS
	/* int a[] = {2, 1, 3, 4, 5};
	int n = sizeof a / sizeof a[0];
	heapperm(a, n, n, &stack_a, &stack_b, argc);
	//print_stacks(stack_a, stack_b); */
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	if (!ps_input_checker(argv))
		return (ft_error());
	push_swap(argc, argv);
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