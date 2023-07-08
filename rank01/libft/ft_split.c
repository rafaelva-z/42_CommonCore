/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:05:32 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/09 14:03:13 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_wordcnt(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*ft_word_i(const char *s, char c, unsigned int i)
{
	char	*str;
	int		len;

	while (i && *s)
	{
		while
		(*s++ == c);
		if (i > 1)
			while
			(*s++ != c);
		s--;
		i--;
	}
	len = ft_wordlen(s, c);
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		wordcnt;
	int		i;

	if (!s)
		return (NULL);
	wordcnt = ft_wordcnt(s, c);
	split = ft_calloc(sizeof(char *), (wordcnt + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (wordcnt--)
	{
		split[i] = ft_word_i(s, c, i + 1);
		i++;
	}
	split[i] = 0;
	return (split);
}

/* int	main(void)
{
	char *ptr = "    split       this for   me  !       ";
	char **split = ft_split(ptr, ' ');
	int i;

	i = 0;
	while (split[i])
		printf("\nWord: %s", split[i++]);
	printf("\nWord: %s", split[i]);
} */