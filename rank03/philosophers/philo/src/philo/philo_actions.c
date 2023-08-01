/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:14:42 by rvaz              #+#    #+#             */
/*   Updated: 2023/08/01 14:45:50 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

//	Preforms action for (time) time, while checking if the philosopher dies
void	philo_action(long int time, t_program *program, t_philo *philo)
{
	struct timeval	start_time;

	update_time(&start_time, NULL);
	update_time(&program->curr_time, &program->m_time);
	while (time_diff(program->curr_time, start_time) < time)
	{
		if (death_check(program, philo))
			return ;
		update_time(&program->curr_time, &program->m_time);
	}
}

void	philo_think(t_program *program, t_philo *philo)
{
	philo->state = THINK;
	print_msg(program, philo->id, MSG_THINK);
}

void	philo_eat(t_program *program, t_philo *philo)
{
	if (grab_forks(program, philo))
	{
		update_time(&philo->last_eat, NULL);
		philo->state = EAT;
		print_msg(program, philo->id, MSG_EAT);
		philo->times_eaten++;
		if (program->times_must_eat)
			check_eat_count(program, philo);
		philo_action(program->time_eat, program, philo);
		release_forks(program, philo);
	}
}

void	philo_sleep(t_program *program, t_philo *philo)
{
	philo->state = SLEEP;
	print_msg(program, philo->id, MSG_SLEEP);
	philo_action(program->time_sleep, program, philo);
}
