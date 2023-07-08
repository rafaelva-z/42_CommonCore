/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:24:35 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/18 22:16:37 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *)s)[i] != (unsigned char)c)
		i++;
	if (i < n && ((unsigned char *)s)[i] == (unsigned char)c)
		return (&((unsigned char *)s)[i]);
	return (NULL);
}

/*
#include <stdio.h>
int	main()
{
	unsigned char s[] = "Olab";
	unsigned char *s2 = ft_memchr(s, 'a', 2);
	printf("result: %s", s2);
}
*/