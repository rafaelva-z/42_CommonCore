/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputhex_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:50:29 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/27 10:52:19 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nputhex_fd(unsigned long n, char *hex_case, int fd)
{
	if (n < 16)
		return (ft_nputchar_fd(hex_case[n], fd));
	return (ft_nputhex_fd(n / 16, hex_case, fd)
		+ ft_nputchar_fd(hex_case[n % 16], fd));
}

