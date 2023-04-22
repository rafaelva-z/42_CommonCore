/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:02:57 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/22 15:08:28 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static void	ft_conversion(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		ft_putnbr_fd(va_arg(args, unsigned int), 1); // Missing
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x')
		ft_putnbr_fd(va_arg(args, unsigned int), 1); // Missing
	else if (c == 'X')
		ft_putnbr_fd(va_arg(args, unsigned int), 1); // Missing
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else
		ft_putchar_fd('%', 1); // If '%' isn't followed by one of these?
}

int	ft_printf(char *text, ...)
{
	va_list	args;
	int		i;
	int		count; // long int?

	i = 0;
	count = 0;
	va_start(args, text);
	if(ft_printf_checker(text, args);
	while (text[i])
	{
		if (text[i] == '%')
			ft_conversion(text[++i], args);
		else
			ft_putchar_fd(text[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
