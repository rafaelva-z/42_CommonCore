/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:25:43 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/30 16:16:46 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = create_stack(argv, argc);
	stack_b = NULL;
	if (argc > 1 && ps_input_checker(argv))
	{
		if (ps_solve_checker(stack_a, stack_b))
			return (0);
		if (argc - 1 <= 5)
			ps_bruteforce(&stack_a, &stack_b);
		else if (argc < 1600)
			ps_newsort(&stack_a, &stack_b, argc - 1);
		free_stacks(&stack_a, &stack_b);
		return (0);
	}
	free_stacks(&stack_a, &stack_b);
	return (ft_error());
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