/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:19:58 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/17 15:40:53 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n - 1 && s1[i])
		i++;
	c1 = s1[i];
	c2 = s2[i];
	return (c1 - c2);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char s1[] = "Hello World";
	char s2[] = "Hello Mister 42";
	size_t size = 100;

	printf("strncmp   : %d\n",strncmp(s1, s2, size));
	printf("ft_strncmp: %d\n",ft_strncmp(s1, s2, size));
}
*/