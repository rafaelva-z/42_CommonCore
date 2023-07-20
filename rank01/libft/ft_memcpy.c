/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:36:54 by rvaz              #+#    #+#             */
/*   Updated: 2023/03/10 16:36:54 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!src && !dest)
		return (NULL);
	while (++i < n)
		((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int	main()
{
	size_t bytes = 2;
	
	unsigned char ptr[] = "Hello";
	unsigned char ptr2[bytes];
	unsigned char ptr3[] = "Hello";
	unsigned char ptr4[bytes];
	printf("\nTEST || memcpy(%s, %s, %ld)\n\n",ptr2, ptr, bytes);
	printf("----------------------------------\n");
	printf("memcpy: %s\n", (unsigned char *)memcpy(ptr2, ptr, bytes));
	printf("ft_memcpy: %s\n", (unsigned char *)ft_memcpy(ptr4, ptr3, bytes));
	printf("----------------------------------\n");
}
*/