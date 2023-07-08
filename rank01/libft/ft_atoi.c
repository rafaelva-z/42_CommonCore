/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:20:10 by rvaz              #+#    #+#             */
/*   Updated: 2023/03/10 15:20:10 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long int	result;
	int			i;
	int			signal;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	signal = (nptr[i] != '-') - (nptr[i] == '-');
	i += ((nptr[i] == '+') || (nptr[i] == '-'));
	result = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
		result = (result * 10) + (nptr[i++] - '0');
	return ((int)result * signal);
}
