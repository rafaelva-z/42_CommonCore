/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:33:27 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/06 18:06:19 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
NOTE:	If the pointers aren't NULL terminated, the test output will be different
		because in my test the functions are using different variables. (ptr1-4)
		this is only a test issue with no pratical difference.
*/
char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	ptr3[20] = "mister";
	char	ptr4[] = "-just walking";
	char	ptr[20] = "mister";
	char	ptr2[] = "-just walking";

	printf("\nTEST || strcat(%s, %s)\n\n", ptr, ptr2);
	printf("----------------------------------\n");
	printf("strcat   : %s | \n", strcat(ptr, ptr2));
	printf("ft_strcat: %s | \n", ft_strcat(ptr3, ptr4));
	printf("----------------------------------\n");
}
*/