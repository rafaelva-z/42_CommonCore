/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:39:34 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/31 19:21:22 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long int	time_diff(struct timeval time1, struct timeval time2)
{
	long int	t1;
	long int	t2;

	t1 = (time1.tv_sec * 1000) + (time1.tv_usec / 1000);
	t2 = (time2.tv_sec * 1000) + (time2.tv_usec / 1000);
	
	return (t1 - t2);
}

//updates time to the current time
void	update_time(struct timeval *time, pthread_mutex_t *mutex)
{
	if (mutex)
	{
		pthread_mutex_lock(mutex);
		gettimeofday(time, NULL);
		pthread_mutex_unlock(mutex);
	}
	else
		gettimeofday(time, NULL);
}

//updates time to current time and returns time since start in ms
long int	update_curr_time(t_program *program)
{
	update_time(&program->curr_time, &program->m_time);
	return (time_diff(program->curr_time, program->start_time));
}
