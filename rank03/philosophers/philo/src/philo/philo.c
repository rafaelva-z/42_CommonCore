/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:02:08 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/28 22:27:28 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	start_philos(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philo_amt)
	{
		pthread_mutex_init(&program->philo[i]->mutex, NULL);
		program->philo[i]->id = i;
		program->philo[i]->program = program;
		program->philo[i]->state = THINK;
		program->philo[i]->fork = 1;
		program->philo[i++]->times_eaten = 0;
	}
}

void	assign_left(t_program *program, t_philo *philo)
{
	if (philo->id == 0)
		philo->left_buddy = program->philo[program->philo_amt - 1]->id;
	else
		philo->left_buddy = program->philo[philo->id - 1]->id;
}

void	*philo_routine(void *arg)
{
	t_philo		*philo;
	t_program	*program;

	philo = (t_philo *)arg;
	program = philo->program;
	assign_left(program, philo);
	update_time(&philo->last_eat);
	if (!(philo->id % 2))
		usleep(150);
	while (1)
	{
		if (death_check(program, philo))
			break ;
		if (philo->state == THINK)
			philo_eat(program, philo);
		else if (philo->state == EAT)
			philo_sleep(program, philo);
		else if (philo->state == SLEEP)
			philo_think(program, philo);
	}
	return (NULL);
}
