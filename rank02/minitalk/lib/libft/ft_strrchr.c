/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:50:32 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/17 20:22:32 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (*ptr != '\0')
	{
		i++;
		ptr++;
	}
	if (c == '\0')
		return (ptr);
	while (i-- >= 0)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main()
{
	char	str[] = "Hey miss and mister 42";
	char	*ptr;
	ptr = ft_strrchr(str, '\0');
	printf("\nInput: %s\nOutput: %s\n", str, ptr);
	//&str[~] insert expected returned index
	printf("&ptr:   %p\n&str[]: %p\n",ptr, &str[22]);
}
*/