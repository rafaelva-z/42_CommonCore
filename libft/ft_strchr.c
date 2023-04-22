/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:22:00 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/17 09:58:18 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr && *ptr != (char)c)
		ptr++;
	if (*ptr == (char)c)
		return (ptr);
	return (NULL);
}

/*
#include <stdio.h>
int	main()
{
	char	str[] = "Hey mister 42";
	char	*ptr;
	ptr = strchr(str, 's');
	printf("Input: %s | Output: %s\n", str, ptr);
}
*/