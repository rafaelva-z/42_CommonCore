/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:39:26 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/01 14:58:44 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_nl(char *buffer)
{
	int	i;
	int	j;
	int	a;

	i = -1;
	j = 0;
	a = 0;
	while (buffer[++i] && i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
		{
			a = 1;
			break ;
		}
		buffer[i] = '\0';
	}
	while (buffer[i] && a == 1)
		buffer[j++] = buffer[i++];
	if (a == 0)
		ft_bzero(buffer, BUFFER_SIZE + 1);
	return (a);
}

char	*get_next_line(int fd)
{
	int			i;
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	i = 1;
	line = NULL;
	while (i > 0)
	{
		//printf("buff1: %s\n", buffer);
		if (!buffer[0])
			i = read(fd, buffer, BUFFER_SIZE);
		if (i > 0)
		{
			line = ft_strjoin_nl(line, buffer);
			//printf("line: %s\n", line);
		}
		//printf("buff2: %s\n", buffer);
		if (check_nl(buffer) != 0)
			break ;
	}
	return (line);
}

int	main()
{
	int i;

	i = open("text.txt", O_RDONLY);
	printf("\nBuff_size: %d\n", BUFFER_SIZE);
	printf("Line: '%s'\n", get_next_line(i));
}