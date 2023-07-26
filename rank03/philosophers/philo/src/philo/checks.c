/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:39:55 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/26 15:30:26 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	death_check(t_program *program, t_philo	*philo)
{
	update_curr_time(program);
	if (time_diff(program->curr_time, philo->last_eat) > program->time_die)
	{
		print_death_msg(program, philo->id, philo->state);
		program->end_of_sim = 1;
		philo->state = DEAD;
		return (1);
	}
	return (0);
}

void	check_eat_counts(t_program *program)
{
	int	i;

	i = 0;
	while (program->philo[i])
	{
		pthread_mutex_lock(&program->philo[i]->mutex);
		if (program->philo[i]->times_eaten < program->times_must_eat)
		{
			pthread_mutex_unlock(&program->philo[i]->mutex);
			return ;
		}
		pthread_mutex_unlock(&program->philo[i]->mutex);
		i++;
	}
	program->end_of_sim = 1;
}
