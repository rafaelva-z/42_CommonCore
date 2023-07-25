/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:08:24 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/25 14:31:52 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	values_check(char **argv)
{
	if (ft_atoi(argv[1]) < 1)
	{
		printf("[philo] ERROR - the philosophers didn't show up\n");
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
	values_check(argv);
}

static void	arg_parse(t_program *program, char **argv)
{	
	program->philo_amt = ft_atoi(argv[1]);
	program->time_die = ft_atoi(argv[2]);
	program->time_eat = ft_atoi(argv[3]);
	program->time_sleep = ft_atoi(argv[4]);
	program->eat_amt = ft_atoi(argv[5]);
}

void	create_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philo_amt)
	{
		if (pthread_create(
				&program->threads[i], NULL, philo_th, program->philo[i]) != 0)
		{
			printf("pthread_create() error");
			exit(1);
		}
		i++;
	}
}

void	start_program(t_program *program, int argc, char **argv)
{
	arg_check(argc, argv);
	arg_parse(program, argv);
	program->end_of_sim = 0;
	alloc_philos(program);
	pthread_mutex_init(&program->mutex, NULL);
	update_time(&program->start_time);
}

