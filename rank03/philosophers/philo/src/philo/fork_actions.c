/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:45:34 by rvaz              #+#    #+#             */
/*   Updated: 2023/08/01 15:36:15 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// Philosopher will first grab the right fork and then the left fork
static int	grab_right_left(t_program *program, t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	pthread_mutex_lock(&program->philo[philo->left_philo_id]->mutex);
	if (philo->fork && program->philo[philo->left_philo_id]->fork)
	{
		philo->fork--;
		program->philo[philo->left_philo_id]->fork--;
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&program->philo[philo->left_philo_id]->mutex);
		print_msg(program, philo->id, MSG_TAKE_FORK);
		return (2);
	}
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&program->philo[philo->left_philo_id]->mutex);
	return (0);
}

// Philosopher will first grab the left fork and then the right fork
static int	grab_left_right(t_program *program, t_philo *philo)
{
	pthread_mutex_lock(&program->philo[philo->left_philo_id]->mutex);
	pthread_mutex_lock(&philo->mutex);
	if (philo->fork && program->philo[philo->left_philo_id]->fork)
	{
		philo->fork--;
		program->philo[philo->left_philo_id]->fork--;
		pthread_mutex_unlock(&program->philo[philo->left_philo_id]->mutex);
		pthread_mutex_unlock(&philo->mutex);
		print_msg(program, philo->id, MSG_TAKE_FORK);
		return (2);
	}
	pthread_mutex_unlock(&program->philo[philo->left_philo_id]->mutex);
	pthread_mutex_unlock(&philo->mutex);
	return (0);
}

/*	Philosopher will try to grab the forks in a different order
*	depending on its id, if it can't grab the forks, return 0.
*	This is to avoid deadlocks	*/
int	grab_forks(t_program *program, t_philo *philo)
{
	if (program->philo_amt == 1)
		return (0);
	if (philo->id % 2 == 0)
		return (grab_right_left(program, philo));
	else
		return (grab_left_right(program, philo));
}

/*	Philosopher will release the forks in a different order
*	depending on its id */
void	release_forks(t_program *program, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->mutex);
		pthread_mutex_lock(&program->philo[philo->left_philo_id]->mutex);
		philo->fork++;
		(program->philo[philo->left_philo_id]->fork)++;
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&program->philo[philo->left_philo_id]->mutex);
	}
	else
	{
		pthread_mutex_lock(&program->philo[philo->left_philo_id]->mutex);
		pthread_mutex_lock(&philo->mutex);
		philo->fork++;
		program->philo[philo->left_philo_id]->fork++;
		pthread_mutex_unlock(&program->philo[philo->left_philo_id]->mutex);
		pthread_mutex_unlock(&philo->mutex);
	}
}
