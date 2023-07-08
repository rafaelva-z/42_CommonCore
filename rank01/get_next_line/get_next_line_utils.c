/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:39:29 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/03 16:34:01 by rvaz             ###   ########.fr       */
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
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_nl(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = -1;
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[++j])
	{
		new[i++] = s2[j];
		if (s2[j] == '\n')
			break ;
	}
	new[i] = '\0';
	free(s1);
	return (new);
}

int	ft_check_nl(char *buffer)
{
	int	i;
	int	j;
	int	nl_check;

	i = 0;
	j = 0;
	nl_check = 0;
	while (buffer[i])
	{
		if (nl_check)
			buffer[j++] = buffer[i];
		else if (buffer[i] == '\n')
			nl_check = 1;
		buffer[i++] = '\0';
	}
	return (nl_check);
}
