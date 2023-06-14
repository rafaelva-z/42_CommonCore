/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:25:43 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/14 16:10:43 by rvaz             ###   ########.fr       */
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
		if (!ps_solve_checker(stack_a, stack_b))
		{
			if (argc - 1 <= 5)
				ps_bruteforce(&stack_a, &stack_b);
			else
				ps_radixsort(&stack_a, &stack_b);
			// else
			// 	ps_newsort(&stack_a, &stack_b);
		}
		free_stacks(&stack_a, &stack_b);
		return (0);
	}
	free_stacks(&stack_a, &stack_b);
	return (ft_error());
}
