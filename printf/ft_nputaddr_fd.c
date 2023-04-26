/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputaddr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:45:37 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/26 18:51:34 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nputaddr_fd(unsigned long ptr, int print0x, int fd)
{
	if (!ptr)
		return (ft_nputstr_fd("(nil)", fd));
	if (print0x)
		ft_nputstr_fd("0x", 1);
	return (ft_nputhex_fd(ptr, HEX_LOW, fd) + 2);
}
