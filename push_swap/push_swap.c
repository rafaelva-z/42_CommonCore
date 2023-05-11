/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:21:00 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/11 01:08:08 by rvaz             ###   ########.fr       */
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

int	solve_check(t_list *stack_a, t_list *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->nb > stack_a->next->nb)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	move_condition()
{

}

void brute_solver(t_list **stack_a, t_list **stack_b, int argc)
{
	int	*solve;
	int i;

	solve = calloc(sizeof(int), argc - 1);
	if (!solve)
		return (NULL);
	i = argc - 1;
	solve[i] = 1;
	while (!solve_check(*stack_a, *stack_b) && solve[0] <= 11)
	{
		if (solve[i] == 1)
			sa(&stack_a);
		else if (solve[i] == 2)
			sb(&stack_b);
		else if (solve[i] == 3)
			ss(&stack_a, &stack_b);
		else if (solve[i] == 4)
			ra(&stack_a);
		else if (solve[i] == 5)
			rb(&stack_b);
		else if (solve[i] == 6)
			rs(&stack_a, &stack_b);
		else if (solve[i] == 7)
			rra(&stack_a);
		else if (solve[i] == 8)
			rrb(&stack_b);
		else if (solve[i] == 9)
			rrs(&stack_a, &stack_b);
		else if (solve[i] == 10)
			pa(&stack_a, &stack_b);
		else if (solve[i] == 11)
			pb(&stack_a, &stack_b);

		if (solve[i] < 11)
			solve[i]++;
		else
			solve[i] = 1;
			i--;
	}
	ft_printf("Welp");
}

0 0 0 1