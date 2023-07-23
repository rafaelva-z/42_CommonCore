/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:59:38 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/23 21:20:42 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i++ < program->philo_amt)
	{
		if (pthread_create(&program->threads[i], NULL, philo_th, program) != 0)
		{
			printf("pthread_create() error");
			exit(1);
		}
	}
}

void	*philo_th(void *arg)
{
	t_program	*program;
	t_philo		*philo;

	program = (t_program *)arg;
	philo = malloc(sizeof(t_philo));
	start_philo(philo, program);
	while (philo->state != DEAD)
	{
		update_curr_time(program);
		if (death_check(philo, program))
			break ;
		if (philo->state == THINK /* && starving */)
		{
			if (grab_forks(program, philo))
			{
				philo->state = EAT;
				print_msg(program, philo->id, MSG_EAT);
				timeout(program->time_eat, program, philo);
				release_forks(program, philo);
			}
		}
		else if(philo->state == EAT)
		{
			update_time(&philo->last_eat);
			philo->state = SLEEP;
			print_msg(program, philo->id, MSG_SLEEP);
			timeout(program->time_sleep, program, philo);
		}
		else if (philo->state == SLEEP)
		{
			philo->state = THINK;
			print_msg(program, philo->id, MSG_THINK);
		}
	}
	pthread_mutex_destroy(&philo->mutex);
	free(philo);
	return (NULL);
}
