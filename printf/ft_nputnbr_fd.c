/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nputnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:43:27 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/26 00:33:29 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nputnbr_fd(int n, int fd)
{
	int	count;

	if (n == -2147483648)
	{
		ft_nputstr_fd("-2147483648", fd);
		return (11);
	}
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
