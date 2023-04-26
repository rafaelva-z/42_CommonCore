/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputaddr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:45:37 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/26 01:13:55 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nputaddr_fd(unsigned long ptr, int print0x, int fd)
{
	if (!ptr)
		return (ft_nputstr_fd("(nil)", fd));
	if (print0x)
		ft_nputstr_fd("0x", 1);
	if (ptr < 16)
		return (ft_nputchar_fd(HEX_LOW[ptr % 16], fd));
	return (ft_nputaddr_fd(ptr / 16, 0, fd)
		+ ft_nputchar_fd(HEX_LOW[ptr % 16], fd));
}
