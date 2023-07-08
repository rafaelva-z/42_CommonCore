/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:14:11 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/13 00:31:35 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = dest;
	s = (char *)src;
	if (s == d)
		return (dest);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	int	n = 5;
	int offset = 5;char *s;

	char str1[20] = "Hello Man";
	char *str2;

	str2 = &str1[offset];

	char str3[20] = "Hello Man";
	char *str4;

	str4 = &str3[offset];
	
	printf("\nft_memmove(str2, str1, %d)\n", n);
	printf("INPUT\n");
	printf("str1: %p, %s\n", str1, str1);
	printf("str2: %p, %s\n", str2, str2);
	ft_memmove(str2, str1, n);
	printf("OUTPUT\n");
	printf("str1: %p, %s\n", str1, str1);
	printf("-----------------------------");
		printf("\nmemmove(str4, str3, %d)\n", n);
	printf("INPUT\n");
	printf("str3: %p, %s\n", str3, str3);
	printf("str4: %p, %s\n", str4, str4);
	memmove(str4, str3, n);
	printf("OUTPUT\n");
	printf("str3: %p, %s\n", str3, str3);
}*/