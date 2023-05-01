/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:39:29 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/01 09:43:14 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = '\0';
	return (s);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while
		(str[i++]);
	return (i);
}

char	*ft_strjoin_nl(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;
	
	i = -1;
	j = -1;
	if (!s2)
		return (NULL);
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	if (s1)
	{
		while (s1[++i])
			new[i] = s1[i];
	}
	while (s2[++j])
	{
		new[++i] = s2[j];
		if (s2[j] == '\n')
			break ;
	}
	new[++i] = '\0';
	return (new);
}