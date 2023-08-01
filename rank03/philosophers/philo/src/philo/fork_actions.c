/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:45:34 by rvaz              #+#    #+#             */
/*   Updated: 2023/08/01 14:20:30 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	grab_forks(t_program *program, t_philo *philo)
{
	if (program->philo_amt == 1)
		return (0);
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

void	release_forks(t_program *program, t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	pthread_mutex_lock(&program->philo[philo->left_philo_id]->mutex);
	print_msg(program, philo->id, MSG_PUT_FORK);
	philo->fork++;
	(program->philo[philo->left_philo_id]->fork)++;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&program->philo[philo->left_philo_id]->mutex);
}
