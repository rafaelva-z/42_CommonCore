/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:18:53 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/17 17:01:54 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*subs;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	subs = ft_substr(s1, start, end - start);
	return (subs);
}
/*
int	main(void)
{
	char ptr[] = "  \t \t \n  ddd \n\n\n\t";
	char set[] = " \n\t";
	char *result = ft_strtrim(ptr, set);

	printf("%s\n", result);
}*/