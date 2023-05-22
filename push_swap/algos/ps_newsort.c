/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_newsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:23:01 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/22 16:44:55 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_newsort(t_list **stack_a, t_list **stack_b, int argc)
{
	int *norm_seq;
	t_list *tmp;
	int i;
	
	norm_seq = calloc(sizeof(int), argc - 1);
	if (!norm_seq)
		return ;
	tmp = *stack_a;
	i = -1;
	while (tmp && i < argc - 1)
	{
		norm_seq[++i] = tmp->nb;
		tmp = tmp->next;
	}
	for (int a = 0; a < argc - 1; a++)
		printf("%d", norm_seq[a]);
	printf("\nwelp\n\n");
}