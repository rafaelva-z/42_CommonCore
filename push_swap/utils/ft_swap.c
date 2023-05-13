/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:33:18 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/12 15:55:17 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(void *a, void *b, size_t bytes)
{
	char	*tmp;
	char	*ca;
	char	*cb;

	if (!a || !b || !bytes)
		return ;
	ca = (char *)a;
	cb = (char *)b;
	tmp = calloc(sizeof(char), bytes);
	while (bytes--)
	{
		tmp[bytes] = ca[bytes];
		ca[bytes] = cb[bytes];
		cb[bytes] = tmp[bytes];
	}
	free(tmp);
}
