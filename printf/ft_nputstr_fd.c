/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:36:40 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/26 19:21:18 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nputstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_nputstr_fd("(null)", fd));
	while (s[i])
		i += ft_nputchar_fd(s[i], fd);
	return (i);
}