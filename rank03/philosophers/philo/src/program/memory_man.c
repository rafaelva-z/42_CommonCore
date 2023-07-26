/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:00:35 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/26 13:18:54 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	free_philos(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philo_amt)
	{
		pthread_mutex_destroy(&program->philo[i]->mutex);
		free(program->philo[i++]);
	}
	free(program->threads);
	free(program->philo);
}

void	alloc_philos(t_program *program)
{
	int	i;

	i = 0;
	program->threads = malloc(sizeof(pthread_t) * (program->philo_amt + 1));
	if (!program->threads)
		err_man(2, 0, program);
	program->philo = malloc(sizeof(t_philo *) * (program->philo_amt + 1));
	while (i < program->philo_amt)
	{
		program->philo[i++] = malloc(sizeof(t_philo));
		if (!program->philo)
			err_man(3, 0, program);
	}
}
