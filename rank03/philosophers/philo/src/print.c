/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:00:22 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/23 21:01:42 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Prints a message with the format "(time in ms) (philo id) (message) (str)"
void	print_msg(t_program *program, int id, char *str)
{
	if (str)
		printf("%ldms %d %s\n", update_curr_time(program), id, str);
	else
		printf("%ldms %d\n", update_curr_time(program), id);
}

void	print_death_msg(t_program *program, int id, int state)
{
	if (state == EAT)
		printf("%ldms %d %s\n", update_curr_time(program), id, MSG_DEAD_EAT);
	else if (state == SLEEP)
		printf("%ldms %d %s\n", update_curr_time(program), id, MSG_DEAD_SLEEP);
	else if (state == THINK)
		printf("%ldms %d %s\n", update_curr_time(program), id, MSG_DEAD_THINK);
	else
		printf("%ldms %d %s\n", update_curr_time(program), id, MSG_DEAD);
}
