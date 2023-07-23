/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:49:02 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/23 21:13:06 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_program		program;
	int				i;

	update_time(&program.start_time);
	arg_parse(&program, argc, argv);
	pthread_mutex_init(&program.mutex, NULL);
	create_threads(&program);
	i = 0;
	while (i++ < program.philo_amt)
		pthread_join(program.threads[i], NULL);
	pthread_mutex_destroy(&program.mutex);
	free(program.threads);
	free(program.philo);
	printf("All philosophers are full\n");
}
