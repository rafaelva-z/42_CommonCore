/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:25:43 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/10 17:06:16 by rvaz             ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	//argc < 2 || <= 2 ??
	if (argc < 2 || !input_check(argv))
		return (ft_error());
	stack_a = create_stack(argv, argc);

	while(stack_a->next)
	{
		ft_printf("%d", stack_a->nb);
		stack_a = stack_a->next;
	}
	ft_printf("%d", stack_a->nb);
	
	(void)stack_a;
	(void)stack_b;
}