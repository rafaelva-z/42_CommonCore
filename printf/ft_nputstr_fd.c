/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:36:40 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/27 10:52:49 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nputstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return (ft_nputstr_fd("(null)", fd));
	while (s[i])
		i += ft_nputchar_fd(s[i], fd);
	return (i);
}
