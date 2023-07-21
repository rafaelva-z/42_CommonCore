/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:49:02 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/21 21:30:00 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long int	update_curr_time(t_program *program)
{
	gettimeofday(&program->curr_time, NULL);
	return (program->curr_time.tv_usec - program->start_time.tv_usec);
}

long int	ft_time(struct timeval time, t_program *program)
{
	return (time.tv_usec - program->start_time.tv_usec);
}

void	start_philo(t_philo *philo, t_program *program)
{
	sem_init(&philo->forks, 0, 1);
	philo->isdead = 0;
	philo->program = program;
	philo->state = THINK;
	pthread_mutex_lock(&program->mutex);
	philo->id = program->phil_created++ + 1;
	pthread_mutex_unlock(&program->mutex);
	gettimeofday(&philo->last_eat, NULL);
	printf("%ldms %d is born\n", update_curr_time(program), philo->id);
}

void	*thread_1(void *arg)
{
	t_program	*program;
	t_philo		philo;

	program = (t_program *)arg;
	start_philo(&philo, program);
	while (update_curr_time(program) - ft_time(philo.last_eat, program) < ft_time(philo.last_eat, program) + program->time_die)
	{
		if(program->curr_time.tv_usec - ft_time(philo.last_eat, program) )
		
	}
	printf("%ldms %d died\n", update_curr_time(program), philo.id);
	printf("last eat time %ld", ft_time(philo.last_eat, program));
	sem_destroy(&philo.forks);
	return (NULL);
}

void	create_threads(t_program *program)
{
	int	i;

	i = 0;
	//change i for program.phil_created
	while (i++ < program->phil_amt)
	{
		//printf("%ldms\n", time_since_start(program));
		if (pthread_create(&program->threads[i], NULL, thread_1, program) != 0)
		{
			printf("pthread_create() error");
			exit(1);
		}
	}
}

int	main(int argc, char **argv)
{
	t_program		program;
	int				i;

	gettimeofday(&program.start_time, NULL);
	arg_parse(&program, argc, argv);
	pthread_mutex_init(&program.mutex, NULL);
	create_threads(&program);
	i = 0;
	while (i++ < program.phil_amt)
		pthread_join(program.threads[i], NULL);
}
