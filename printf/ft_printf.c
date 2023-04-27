/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:02:57 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/27 10:54:31 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_conversion(char c, va_list args)
{
	size_t	count;

	count = 0;
	if (c == 'c')
		count = ft_nputchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		count = ft_nputstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		count = ft_nputaddr_fd(va_arg(args, unsigned long), 1);
	else if (c == 'd' || c == 'i')
		count = ft_nputnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		count = ft_nputnbr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		count = ft_nputhex_fd(va_arg(args, unsigned int), HEX_LOW, 1);
	else if (c == 'X')
		count = ft_nputhex_fd(va_arg(args, unsigned int), HEX_HIGH, 1);
	else if (c == '%')
		count = ft_nputchar_fd('%', 1);
	return (count);
}

int	ft_printf(const char *text, ...)
{
	va_list		args;
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	va_start(args, text);
	while (text[i])
	{
		if (text[i] == '%')
			count += ft_conversion(text[++i], args);
		else
			count += ft_nputchar_fd(text[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
