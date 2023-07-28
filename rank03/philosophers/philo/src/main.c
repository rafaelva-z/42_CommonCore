/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:49:02 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/28 19:49:18 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	end_program(t_program *program)
{
	free_philos(program);
	pthread_mutex_destroy(&program->print);
	pthread_mutex_destroy(&program->endsim);
	pthread_mutex_destroy(&program->eatcount);
}

void	join_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philo_amt)
		pthread_join(program->threads[i++], NULL);
}

void	create_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philo_amt)
	{
		if (pthread_create(&program->threads[i], NULL,
				philo_routine, program->philo[i]) != 0)
			err_man(1, i, program);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_program		program;

	start_program(&program, argc, argv);
	start_philos(&program);
	update_time(&program.start_time);
	create_threads(&program);
	join_threads(&program);
	end_program(&program);
}
