/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:45:34 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/26 13:09:36 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// Philosopher will first grab the right fork and then the left fork
int	grab_right_left(t_program *program, t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	pthread_mutex_lock(&program->philo[philo->left_buddy]->mutex);
	if (philo->fork && program->philo[philo->left_buddy]->fork)
	{
		philo->fork--;
		program->philo[philo->left_buddy]->fork--;
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&program->philo[philo->left_buddy]->mutex);
		print_msg(program, philo->id, MSG_TAKE_FORK);
		return (2);
	}
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&program->philo[philo->left_buddy]->mutex);
	return (0);
}

// Philosopher will first grab the left fork and then the right fork
int	grab_left_right(t_program *program, t_philo *philo)
{
	pthread_mutex_lock(&program->philo[philo->left_buddy]->mutex);
	pthread_mutex_lock(&philo->mutex);
	if (philo->fork && program->philo[philo->left_buddy]->fork)
	{
		philo->fork--;
		program->philo[philo->left_buddy]->fork--;
		pthread_mutex_unlock(&program->philo[philo->left_buddy]->mutex);
		pthread_mutex_unlock(&philo->mutex);
		print_msg(program, philo->id, MSG_TAKE_FORK);
		return (2);
	}
	pthread_mutex_unlock(&program->philo[philo->left_buddy]->mutex);
	pthread_mutex_unlock(&philo->mutex);
	return (0);
}

/*	Philosopher will try to grab the forks in a different order
*	depending on its id, if it can't grab the forks, return 0 */
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
		pthread_mutex_lock(&program->philo[philo->left_buddy]->mutex);
		print_msg(program, philo->id, MSG_PUT_FORK);
		philo->fork++;
		(program->philo[philo->left_buddy]->fork)++;
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&program->philo[philo->left_buddy]->mutex);
	}
	else
	{
		pthread_mutex_lock(&program->philo[philo->left_buddy]->mutex);
		pthread_mutex_lock(&philo->mutex);
		print_msg(program, philo->id, MSG_PUT_FORK);
		philo->fork++;
		program->philo[philo->left_buddy]->fork++;
		pthread_mutex_unlock(&program->philo[philo->left_buddy]->mutex);
		pthread_mutex_unlock(&philo->mutex);
	}
}
