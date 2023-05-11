/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:25:43 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/11 17:09:15 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
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

static void heapPermutation(int *a, int size, int n, t_list **stack_a, t_list **stack_b, int argc)
{
	
	int	tmp;
    if (size == 1)
	{
		ft_lstclear(stack_a, ft_bzero_int);
		*stack_a = create_stack_int(a, argc);
		//print_stacks(*stack_a, *stack_b);
		brute_solver(stack_a, stack_b, argc);
		ft_printf("%d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5]);
        return ;
    }
 
    for (int i = 0; i < size; i++)
	{
        heapPermutation(a, size - 1, n, stack_a, stack_b, argc);
        if (size % 2 == 1)
		{
            tmp = a[0];
			a[0] = a[size - 1];
			a[size - 1] = tmp;
		}
        else
		{
            tmp = a[i];
			a[i] = a[size - 1];
			a[size - 1] = tmp;
		}
    }
	
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

	/*HEAPERMUTATIONS*/
	int a[] = {2, 1, 3, 4, 5, 6};
	int n = sizeof a / sizeof a[0];
	heapPermutation(a, n, n, &stack_a, &stack_b, argc);
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