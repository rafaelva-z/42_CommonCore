/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:40:46 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/17 14:53:14 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	i = 0;
	j = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	j = dlen;
	if (size == 0 || size <= dlen)
		return (slen + size);
	while (src[i] && i < size - dlen - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (dlen + slen);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char src[] = "testetstst";
	char dst[14] = "a";
	size_t size = 15;

	printf("ft_strlcat: %ld\n",ft_strlcat(dst, src, size));
	printf("dest: %s\n", dst);
}
*/