/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:39:34 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/26 14:58:26 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//returns time since start in ms
long int	time_from_start(t_program program)
{
	long int	sec;
	long int	ms;

	sec = program.curr_time.tv_sec - program.start_time.tv_sec;
	ms = program.curr_time.tv_usec - program.start_time.tv_usec;
	return ((sec * 1000) + (ms / 1000));
}

//time difference between time1 and time2
long int	time_diff(struct timeval time1, struct timeval time2)
{
	long int	sec;
	long int	ms;

	sec = time1.tv_sec - time2.tv_sec;
	ms = time1.tv_usec - time2.tv_usec;
	return ((sec * 1000) + (ms / 1000));
}

//updates time to the current time
void	update_time(struct timeval *time)
{
	gettimeofday(time, NULL);
}

//updates time to current time and returns time since start in ms
long int	update_curr_time(t_program *program)
{
	gettimeofday(&program->curr_time, NULL);
	return (time_from_start(*program));
}
