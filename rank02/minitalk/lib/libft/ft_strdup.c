/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:23:53 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/19 15:51:32 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		slen;
	char	*s2;

	i = 0;
	slen = ft_strlen(s);
	s2 = ft_calloc(sizeof(char), slen + 1);
	if (!s2)
		return (NULL);
	while (i <= slen)
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}

/*
#include <stdio.h>
int	main(void)
{
	char s1[] = "Helloooo";
	char *s2;

	s2 = ft_strdup(s1);
	printf("s2: %s", s2);
}
*/