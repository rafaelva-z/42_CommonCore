/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:00:22 by rvaz              #+#    #+#             */
/*   Updated: 2023/08/01 15:34:14 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Prints a message with the format "(time in ms) (philo id) (message) (str)"
void	print_msg(t_program *program, int id, char *str)
{
	long int	time;

	id++;
	pthread_mutex_lock(&program->m_print);
	pthread_mutex_lock(&program->m_endsim);
	if (program->end_of_sim)
	{
		pthread_mutex_unlock(&program->m_endsim);
		pthread_mutex_unlock(&program->m_print);
		return ;
	}
	pthread_mutex_unlock(&program->m_endsim);
	time = update_curr_time(program);
	if (str)
		printf("%ldms %d %s\n", time, id, str);
	else
		printf("%ldms %d\n", time, id);
	if (!ft_strncmp(str, MSG_TAKE_FORK, 20))
		printf("%ldms %d %s\n", time, id, str);
	pthread_mutex_unlock(&program->m_print);
}

void	print_death_msg(t_program *program, int id, int state)
{
	if (state == EAT)
		print_msg(program, id, MSG_DEAD);
	else if (state == SLEEP)
		print_msg(program, id, MSG_DEAD);
	else if (state == THINK)
		print_msg(program, id, MSG_DEAD);
	else
		print_msg(program, id, MSG_DEAD);
}
