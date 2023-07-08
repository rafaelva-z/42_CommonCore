/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:19:50 by rvaz              #+#    #+#             */
/*   Updated: 2023/03/10 15:19:50 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
MISMATCHING BEHAVIOUR WITH "memset"

-when n is bigger than the alocated space,
behaviour is different (apparently memset doesn't change
the values in memory direcly?).
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = c;
	return (s);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	int character = '-';
	int bytes = 5;
	unsigned char ptr2[] = "Hello";
	unsigned char ptr[] = "Hello";
	printf("\nTEST || memset(ptr, '%c', %d)\n\n",character, bytes);
	printf("ptr content 1: %s | 2: %s\n",ptr, ptr2);
	printf("----------------------------------\n");
	printf("memset   : %s | ", (unsigned char *)memset(ptr, character, bytes));
	printf("ft_memset: %s\n", (unsigned char *)ft_memset(ptr2, character, bytes));
	printf("----------------------------------\n");
}
*/