/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:11:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/20 14:12:16 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		a;

	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	a = 0;
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[a])
	{
		ptr[i] = s2[a];
		i++;
		a++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
int	main(void)
{
	char *s1 = "Hello";
	char *s2 = " mister 42!";
	char *s3 = ft_strjoin(s1, s2);
	
	printf("result: %s", s3);
}*/