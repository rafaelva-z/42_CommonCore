/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputaddr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:45:37 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/27 16:33:37 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nputaddr(unsigned long ptr)
{
	if (!ptr)
		return (ft_nputstr("(nil)"));
	return (ft_nputstr("0x") + ft_nputhex(ptr, HEX_LOW));
}
