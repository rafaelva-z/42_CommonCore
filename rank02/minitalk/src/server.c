/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:45:55 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/12 18:42:32 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void sighandler(int signal)
{
	static int	bits;
	static int	c;
	
	if (signal == SIGUSR1)
		c |= (0x01 << bits);
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction ssig;
	int	pid;

	pid = getpid();
	ft_printf("\033[96m[minitalk]\033[0m Server PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, sighandler);
		signal(SIGUSR2, sighandler);
		sigaction(SIGUSR1, NULL, &ssig);
		pause();
	}
}