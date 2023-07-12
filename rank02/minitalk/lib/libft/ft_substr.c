/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:19:44 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/19 02:21:12 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*remove this (strlen)
#include <stdlib.h>
#include <stdio.h>*/

char	*alloc_substr(char const *s, char *subs, size_t len, size_t i)
{
	if (ft_strlen(s) > len)
		subs = malloc(len + 1);
	else
		subs = malloc(ft_strlen(s) + 1);
	if (!subs)
		return (NULL);
	while (subs && len--)
	{
		subs[i] = s[i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	slen;

	i = 0;
	subs = NULL;
	slen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (len == 0 || start >= slen)
	{
		subs = malloc(1);
		if (!subs)
			return (NULL);
		*subs = '\0';
		return (subs);
	}
	if (len > slen)
		len = slen;
	while (start--)
		s++;
	return (alloc_substr(s, subs, len, i));
}
/*
int	main(void)
{
	char	s[] = "Hello 42, im writting something.";
	char	*subs;

	subs = ft_substr(s, 31, 1);
	printf ("Result: %s\n", subs);
}
*/