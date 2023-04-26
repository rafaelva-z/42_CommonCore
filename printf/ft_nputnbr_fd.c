/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:43:27 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/26 15:03:14 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nputnbr_fd(long n, int fd)
{
	long int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count += ft_nputchar_fd('-', fd);
	}
	if (n > 9)
	{
		count += ft_nputnbr_fd(n / 10, fd);
		count += ft_nputnbr_fd(n % 10, fd);
	}
	else
		count += ft_nputchar_fd(n + '0', fd);
	return (count);
}
