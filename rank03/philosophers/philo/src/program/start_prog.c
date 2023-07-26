/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:08:24 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/26 14:40:52 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	values_check(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 1)
	{
		printf("[philo] ERROR - the philosophers didn't show up\n");
		exit(0);
	}
	if (argc == 6 && ft_atoi(argv[5]) < 1)
	{
		printf("[philo] ERROR - the philosophers aren't hungry at the moment\n");
		exit(0);
	}
}

static void	arg_check(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
	{
		if (argc < 5)
			printf("[philo] ERROR - Not enough arguments\n");
		else if (argc > 6)
			printf("[philo] ERROR - Too many arguments\n");
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
				printf("[philo] ERROR - invalid char (arg%d, char%d)\n", j, i);
				exit(0);
			}
		}
	}
	values_check(argc, argv);
}

static void	arg_parse(t_program *program, int argc, char **argv)
{
	program->philo_amt = ft_atoi(argv[1]);
	program->time_die = ft_atoi(argv[2]);
	program->time_eat = ft_atoi(argv[3]);
	program->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		program->times_must_eat = ft_atoi(argv[5]);
	else
		program->times_must_eat = 0;
}

void	start_program(t_program *program, int argc, char **argv)
{
	arg_check(argc, argv);
	arg_parse(program, argc, argv);
	program->end_of_sim = 0;
	alloc_philos(program);
	pthread_mutex_init(&program->mutex, NULL);
}
