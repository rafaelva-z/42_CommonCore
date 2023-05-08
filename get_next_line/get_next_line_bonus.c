/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:39:26 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/05 16:29:41 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int			i;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	i = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		if (fd >= 0 && fd <= FOPEN_MAX)
			ft_bzero(buffer[fd], BUFFER_SIZE + 1);
		return (NULL);
	}
	while (i > 0)
	{
		if (!buffer[fd][0])
			i = read(fd, buffer[fd], BUFFER_SIZE);
		if (i > 0)
			line = ft_strjoin_nl(line, buffer[fd]);
		if (ft_check_nl(buffer[fd]))
			break ;
	}
	return (line);
}

/*
//Prints a line from each file one at a time 
int	main(void)
{
	int		fd[2];
	int		i;
	char	*line;
	int		check;

	check = 1;
	i = 0;
	fd[0] = open("text1.txt", O_RDONLY);
	fd[1] = open("text2.txt", O_RDONLY);
	printf("\nBuff_size: %d\n", BUFFER_SIZE);
	while (check)
	{
		line = get_next_line(fd[i]);
		if (!line)
		{
			check = 0;
			printf("\n");
		}
		printf("Line: %s", line);
		free(line);
		if (i == 0)
			i++;
		else
			i--;
	}
}*/