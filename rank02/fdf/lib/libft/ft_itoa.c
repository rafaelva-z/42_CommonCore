/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:13:37 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/19 15:13:26 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlenn(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*calculate(char *str, long int num, int numlen)
{
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}		
	while (num > 0)
	{
		str[numlen--] = num % 10 + 48;
		num /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			numlen;
	long int	num;

	num = n;
	numlen = ft_numlenn(num);
	str = (char *)ft_calloc(sizeof(str), numlen-- + 1);
	if (!str)
		return (NULL);
	return (calculate(str, num, numlen));
}

/*
int	main(void)
{
	//char *ptr = ft_itoa(1023);
	//char *ptr2 = ft_itoa(-1209);

	printf("Expected: 1\n");
	printf("Result:   %s\n", ft_itoa(1));
	printf("Expected: -1\n");
	printf("Result:   %s\n", ft_itoa(-1));
	printf("Expected: 0\n");
	printf("Result:   %s\n", ft_itoa(0));
	printf("Expected: 2147483647\n");
	printf("Result:   %s\n", ft_itoa(2147483647));
	printf("Expected: -2147483648\n");
	printf("Result:   %s\n", ft_itoa(-2147483648));
}*/