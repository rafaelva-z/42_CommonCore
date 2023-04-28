/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:39:26 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/28 15:59:36 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_next_line(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
			return (i);
	}
	return (-1);
}

// wont work bc it will do a bunch of '\0' on the starting "line"
char	*get_next_line(int fd)
{
	int			i;
	static char	buffer[BUFFER_SIZE + 1];
	char 		line[BUFFER_SIZE + 1];

	i = 0;
	ft_bzero(buffer, BUFFER_SIZE + 1);
	ft_bzero(line, BUFFER_SIZE + 1);

	while (check_next_line(buffer) < 0)
	{
		if(!buffer[0])
			read(fd, buffer, BUFFER_SIZE);
		else
		{
			line = ft_strjoin(line, buffer); 
			ft_bzero(buffer, BUFFER_SIZE);
		}
	}
	return (line);
}

int	main()
{
	printf("\nBuff_size: %d\n", BUFFER_SIZE);
	printf("Buffer: '%s'\n", get_next_line(open("text.txt", O_RDONLY)));
	printf("Buffer: '%s'\n", get_next_line(open("text.txt", O_RDONLY)));
}