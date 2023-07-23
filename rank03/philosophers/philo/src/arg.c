/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:08:24 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/23 21:08:43 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	arg_check(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 6)
	{
		if (argc > 6)
			printf("[philo] ERROR - Too many arguments\n");
		else if (argc < 6)
			printf("[philo] ERROR - Not enough arguments\n");
		exit(0);
	}
	j = 0;
	while (argv[++j])
	{
		i = -1;
		while (argv[j][++i])
		{
			if (!ft_isdigit(argv[j][i]))
			{
				printf("[philo] ERROR - invalid charcter (arg%d, char%d)\n",
					j, i);
				exit(0);
			}
		}
	}
}

void	arg_parse(t_program *program, int argc, char **argv)
{
	arg_check(argc, argv);
	program->philo_amt = ft_atoi(argv[1]);
	program->philo_alive = 0;
	program->time_die = ft_atoi(argv[2]);
	program->time_eat = ft_atoi(argv[3]);
	program->time_sleep = ft_atoi(argv[4]);
	program->eat_amt = ft_atoi(argv[5]);
	program->threads = malloc(sizeof(pthread_t) * program->philo_amt + 1);
	program->philo = malloc(sizeof(t_philo *) * program->philo_amt + 1);
	if (!program->threads || !program->philo)
	{
		printf("[philo] ERROR - malloc failed\n");
		exit(0);
	}
}

