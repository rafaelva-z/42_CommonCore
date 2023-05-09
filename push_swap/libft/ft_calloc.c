/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:23:29 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/06 12:23:29 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
#include<stdio.h>
int main()
{
    //change bzero to memset with a letter to test
    int i = 0;
    char	*phrase1;
    char	*phrase2;
    int	nmemb = 5;
    
    phrase1 = ft_calloc(nmemb, 0);
    phrase2 = calloc(nmemb, 0);
    while (i < nmemb + 1)
    {
        //printf("Phrase 1 Byte%d: %c\n", i, phrase1[i]);
        i++;
    }
    i = 0;
    while (i < nmemb + 1)
    {
        //printf("Phrase 2 Byte%d: %c\n", i, phrase2[i]);
        i++;
    }
	printf("");
}
*/