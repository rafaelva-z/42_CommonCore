/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:49:02 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/24 16:43:17 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philo_amt)
	{
		if (pthread_create(&program->threads[i++], NULL, philo_th, program) != 0)
		{
			printf("pthread_create() error");
			exit(1);
		}
	}
}

void	join_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philo_amt)
		pthread_join(program->threads[i++], NULL);
}

int	main(int argc, char **argv)
{
	int	i = 0;
	t_program		program;
	
	arg_parse(&program, argc, argv);
	pthread_mutex_init(&program.mutex, NULL);
	update_time(&program.start_time);
	start_philos(&program);
	create_threads(&program);
	join_threads(&program);
	pthread_mutex_destroy(&program.mutex);
	while (i < program.philo_amt)
		pthread_mutex_destroy(&program.philo[i++]->mutex);
	free(program.threads);
	free(program.philo);
}
