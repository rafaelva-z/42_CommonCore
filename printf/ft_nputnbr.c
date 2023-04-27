/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:43:27 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/27 16:37:37 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nputnbr(long n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count += ft_nputchar('-');
	}
	if (n > 9)
	{
		count += ft_nputnbr(n / 10);
		count += ft_nputnbr(n % 10);
	}
	else
		count += ft_nputchar(n + '0');
	return (count);
}
