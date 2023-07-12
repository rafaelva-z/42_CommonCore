/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:10:31 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/12 18:33:37 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	send_char(int pid, char c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if ((c & (0x01 << bits)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bits++;
	}
}

static void	arg_check(int argc, char **argv)
{
	int i;
	
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

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	arg_check(argc, argv);
	i = 0;
	pid = ft_atoi(argv[1]);
	if(argv[2][0])
	{
		while (argv[2][i])
		{
			send_char(pid, argv[2][i]);
			i++;
		}
		send_char(pid, '\n');
	}
}