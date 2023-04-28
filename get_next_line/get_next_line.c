/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:39:26 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/28 11:43:53 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];

	read(fd, buffer, BUFFER_SIZE);
	printf("Buff_size: %d\n", BUFFER_SIZE);
	printf("Buffer: %s\n", buffer);
}

int	main()
{
	get_next_line(open("text.txt", O_RDONLY));
	get_next_line(open("text.txt", O_RDONLY));
}