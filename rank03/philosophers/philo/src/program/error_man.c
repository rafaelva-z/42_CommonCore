/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:10:32 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/26 13:32:04 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	err_man(int err_id, int val, t_program *program)
{
	if (err_id == 1)
	{
		perror("[philo] - Error while creating threads");
		while (--val)
			pthread_join(program->threads[val], NULL);
		end_program(program);
	}
	else if (err_id == 2)
		perror("[philo] - Error while allocating memory");
	else if (err_id == 3)
	{
		perror("[philo] - Error while allocating memory");
		while (--val)
			free(program->philo[val]);
		free(program->philo);
	}
	exit(1);
}
