/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:10:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/18 20:11:22 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

//minimum usleep tested time is 10
static void	send_char(int pid, char c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if ((c & (1 << bits)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bits++;
	}
}

static void	arg_check(int argc, char **argv)
{
	int	i;

	if (argc > 3)
	{
		ft_printf("[minitalk] ERROR - Too many arguments | Usage: ");
		ft_printf("./client \"PID\" \"Message\"");
		exit(0);
	}
	else if (argc < 3)
	{
		ft_printf("[minitalk] ERROR - Not enough arguments | Usage: ");
		ft_printf("./client \"PID\" \"Message\"");
		exit(0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]) || i == 9)
		{
			ft_printf("[minitalk] ERROR - Invalid PID");
			exit(0);
		}
		else
			i++;
	}
}

void	sighandler(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("\033[96m[minitalk]\033[0m Message received by server\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	arg_check(argc, argv);
	i = 0;
	pid = ft_atoi(argv[1]);
	if (argv[2][0])
	{
		signal(SIGUSR1, sighandler);
		while (argv[2][i])
		{
			send_char(pid, argv[2][i]);
			i++;
		}
		send_char(pid, '\0');
		while (1)
			;
	}
}
