/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:02:57 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/21 18:04:06 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"


int	ft_printf(char *text, ...)
{
	long long int		i;
	va_list	args;

	i = 0;
	va_start(args, text);
	while (text[i])
	{
		if (text[i] == '%')
		{	
		if (text[++i] == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (text[i] == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (text[i] == 'p')
		ft_putnbr_fd(va_arg(args, int), 1); // Missing
	else if (text[i] == 'd' && text[i] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (text[i] == 'u')
		ft_putnbr_fd(va_arg(args, int), 1); // Missing
	else if (text[i] == 'x')
		ft_putnbr_fd(va_arg(args, int), 1); // Missing
	else if (text[i] == 'X')
		ft_putnbr_fd(va_arg(args, int), 1); // Missing
	else if (text[i] == '%')
		ft_putchar_fd('%', 1);
	else
		ft_putchar_fd('%', 1); // If '%' isn't followed by one of these?
			i++;
		}
		else
			ft_putchar_fd(text[i++], 1);
	}
	return (ft_strlen(text));
	va_end(args);
}
