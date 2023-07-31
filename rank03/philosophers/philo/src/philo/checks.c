/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:39:55 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/31 17:48:55 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

//	Check if the simulation has ended
static int	endsim_check(t_program *program)
{
	pthread_mutex_lock(&program->m_eatcount);
	if (program->done_eating == program->philo_amt)
	{
		pthread_mutex_lock(&program->m_endsim);
		program->end_of_sim = 1;
		pthread_mutex_unlock(&program->m_endsim);
		pthread_mutex_unlock(&program->m_eatcount);
		return (1);
	}
	pthread_mutex_unlock(&program->m_eatcount);
	pthread_mutex_lock(&program->m_endsim);
	if (program->end_of_sim == 1)
	{
		pthread_mutex_unlock(&program->m_endsim);
		return (1);
	}
	pthread_mutex_unlock(&program->m_endsim);
	return (0);
}

//	Check if the philo passed as parameter died
int	death_check(t_program *program, t_philo	*philo)
{
	update_curr_time(program);
	if (time_diff(program->curr_time, philo->last_eat) > program->time_die)
	{
		print_death_msg(program, philo->id, philo->state);
		pthread_mutex_lock(&program->m_endsim);
		program->end_of_sim = 1;
		pthread_mutex_unlock(&program->m_endsim);
		philo->state = DEAD;
		return (1);
	}
	return (endsim_check(program));
}

void	check_eat_count(t_program *program, t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->times_eaten != program->times_must_eat)
		return ;
	pthread_mutex_lock(&program->m_eatcount);
	program->done_eating++;
	pthread_mutex_unlock(&program->m_eatcount);
}
