/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_newsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:23:01 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/23 14:20:31 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int *normalize_seq(t_list **stack_a, int argc)
{
	int *norm_seq;
	t_list *tmp;
	int i;

	norm_seq = calloc(sizeof(int), argc - 1);
	if (!norm_seq)
		return (NULL);
	tmp = *stack_a;
	i = -1;
	while (tmp && i < argc - 1)
	{
		norm_seq[++i] = tmp->nb;
		tmp = tmp->next;
	}
	return (norm_seq);
}

void	ps_newsort(t_list **stack_a, t_list **stack_b, int argc)
{
	int	*norm_seq;

	norm_seq = normalize_seq(stack_a, argc);

	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);

	while(/*procurar melhor escolha*/)
	{}

	free(norm_seq);

	print_stacks(*stack_a, *stack_b);
	printf("\nwelp\n\n");
}