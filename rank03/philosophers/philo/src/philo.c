/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:02:08 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/23 21:02:47 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_philo(t_philo *philo, t_program *program)
{
	pthread_mutex_init(&philo->mutex, NULL);
	philo->program = program;
	philo->state = THINK;
	philo->fork = 1;
	pthread_mutex_lock(&program->mutex);
	program->philo[program->philo_alive] = philo;
	philo->id = program->philo_alive++;
	pthread_mutex_unlock(&program->mutex);
	usleep(100000);
	update_time(&philo->last_eat);
	print_msg(program, philo->id, MSG_BORN);
}

int	death_check(t_philo	*philo, t_program *program)
{
	if (time_diff(program->curr_time, philo->last_eat) > program->time_die)
	{
		print_death_msg(program, philo->id, philo->state);
		philo->state = DEAD;
		return (1);
	}
	return (0);
}


//check if philo dies while sleeping/eating
void	timeout(long int time, t_program *program, t_philo *philo)
{
	struct timeval	start_time;

	update_time(&start_time);
	update_time(&program->curr_time);
	while (time_diff(program->curr_time, start_time) < time)
	{
		if (death_check(philo, program))
			return ;
		update_time(&program->curr_time);
	}
}

int	grab_forks(t_program *program, t_philo *philo)
{
	if (philo->id > 0)
	{
		pthread_mutex_lock(&philo->mutex);
		pthread_mutex_lock(&program->philo[philo->id - 1]->mutex);
		usleep(100);
		if (philo->fork && program->philo[philo->id - 1]->fork)
		{
			philo->fork--;
			program->philo[philo->id - 1]->fork--;
			print_msg(program, philo->id, MSG_TAKE_FORK);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&program->philo[philo->id - 1]->mutex);
			return (2);
		}
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&program->philo[philo->id - 1]->mutex);
	}
	else
	{
		pthread_mutex_lock(&program->philo[program->philo_amt - 1]->mutex);
		pthread_mutex_lock(&philo->mutex);
		if (philo->fork && program->philo[program->philo_amt - 1]->fork)
		{
			philo->fork--;
			program->philo[program->philo_amt - 1]->fork--;
			print_msg(program, philo->id, MSG_TAKE_FORK);
			pthread_mutex_unlock(
				&program->philo[program->philo_amt - 1]->mutex);
			pthread_mutex_unlock(&philo->mutex);
			return (2);
		}
		pthread_mutex_unlock(&program->philo[program->philo_amt - 1]->mutex);
		pthread_mutex_unlock(&philo->mutex);
	}
	return (0);
}

void	release_forks(t_program *program, t_philo *philo)
{
	if (philo->id > 0)
	{
		pthread_mutex_lock(&philo->mutex);
		pthread_mutex_lock(&program->philo[philo->id - 1]->mutex);
		philo->fork++;
		(program->philo[philo->id - 1]->fork)++;
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&program->philo[philo->id - 1]->mutex);
		print_msg(program, philo->id, MSG_PUT_FORK);
	}
	else
	{
		pthread_mutex_lock(&program->philo[program->philo_amt - 1]->mutex);
		pthread_mutex_lock(&philo->mutex);
		philo->fork++;
		program->philo[program->philo_amt - 1]->fork++;
		pthread_mutex_unlock(&program->philo[program->philo_amt - 1]->mutex);
		pthread_mutex_unlock(&philo->mutex);
		print_msg(program, philo->id, MSG_PUT_FORK);
	}
}