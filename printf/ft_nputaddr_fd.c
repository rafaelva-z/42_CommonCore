/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputaddr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:45:37 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/27 10:52:12 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nputaddr_fd(unsigned long ptr, int fd)
{
	if (!ptr)
		return (ft_nputstr_fd("(nil)", fd));
	return (ft_nputstr_fd("0x", fd), ft_nputhex_fd(ptr, HEX_LOW, fd));
}
