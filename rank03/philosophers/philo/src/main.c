/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:49:02 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/25 14:07:19 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	end_program(t_program *program)
{
	free_philos(program);
	pthread_mutex_destroy(&program->mutex);
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
	t_program		program;

	printf("philosophers are eating\n");
	start_program(&program, argc, argv);
	start_philos(&program);
	create_threads(&program);
	join_threads(&program);
	end_program(&program);
}
