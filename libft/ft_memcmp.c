/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:24:30 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/17 11:19:11 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (n)
	{
		while (n-- > 1 && *ss1 == *ss2)
		{
			ss1++;
			ss2++;
		}
		return (*ss1 - *ss2);
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	unsigned char *s1 = "";
	unsigned char *s2 = "Hey Miss 42";

	printf("ft_memcmp: %d\n", ft_memcmp(s1, s2, 0));
	printf("   memcmp: %d\n", memcmp(s1, s2, 0));
}
*/