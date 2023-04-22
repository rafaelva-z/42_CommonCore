/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:41:07 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/22 15:09:06 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *ptr = "42";
	printf("┌--PRINTF---------------------------------\n");
	printf("|\n");
	printf("| char   >[%c]-[%c]-[%c]-[%c]-[%c]-[%c]\n", 'a', 'A', '0', '9', '\t', '\0');
	printf("| string >[%s]-[%s]\n", "Hello", "A1b2C\0d4");
	printf("| pointer>[%p]-[%p]\n", NULL, ptr);
	// printf("| %d\n", 10.5);
	printf("| int    >[%x]-[%i]-[%i]-[%i]\n", 0, 13249, 2147483647, -2147483647);
	printf("| uns int>[%i]-[%i]-[%i]-[%i]\n", 0, 13249, 2147483647, -2147483647);
	printf("| [%x]\n", 10);
	printf("| [%X]\n", 10);
	printf("| [%%]\n");
	printf("|\n");
	ft_printf("├--FT_PRINTF------------------------------\n");
	ft_printf("|\n");
	ft_printf("| char   >[%c]-[%c]-[%c]-[%c]-[%c]-[%c]\n", 'a', 'A', '0', '9', '\t', '\0');
	ft_printf("| string >[%s]-[%s]\n", "Hello", "A1b2C\0d4");
	ft_printf("| pointer>[%p]-[%p]\n", NULL, ptr);
	// ft_printf("| %d\n",);
	ft_printf("| int    >[%i]-[%i]-[%i]-[%i]\n", 0, 13249, 2147483647, -2147483647);
	ft_printf("| uns int>[%i]-[%i]-[%i]-[%i]\n", 0, 13249, 2147483647, -2147483647);
	ft_printf("| [%x]\n", 10);
	ft_printf("| [%X]\n", 10);
	ft_printf("| [%%]\n");
	ft_printf("|\n");
	ft_printf("└----------------------------------------");
	printf("%#x,\n", 123);	
}
