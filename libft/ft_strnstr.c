/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:33:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/18 22:16:26 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	char *big = "ABC";
	char *little = "MZIRIBMZA";
	
	printf("ft_strnstr: %s\n", ft_strnstr(((void*)0), "fake", 3));
	printf("   strnstr: %s\n", strnstr(((void*)0), "fake", 3));
}   
*/