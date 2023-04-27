/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:50:29 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/27 16:37:18 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nputhex(unsigned long n, char *hex_case)
{
	if (n < 16)
		return (ft_nputchar(hex_case[n]));
	return (ft_nputhex(n / 16, hex_case)
		+ ft_nputchar(hex_case[n % 16]));
}
