/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:49:02 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/22 15:33:07 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_philo(t_philo *philo, t_program *program)
{
	sem_init(&philo->forks, 0, 1);
	philo->program = program;
	philo->state = THINK;
	pthread_mutex_lock(&program->mutex);
	philo->id = program->phil_created++ + 1;
	pthread_mutex_unlock(&program->mutex);
	update_time(&philo->last_eat);
	printf("%ldms %d is born\n", update_curr_time(program), philo->id);
}

//check if philo dies while sleeping/eating
void	timeout(long int time, t_program *program, t_philo *philo)
{
	struct timeval start_time;
	
	update_time(&start_time);
	update_time(&program->curr_time);
	while (time_diff(program->curr_time, start_time) < time)
	{
		if(time_diff(program->curr_time, philo->last_eat) > program->time_die)
		{
			philo->state = DEAD;
			printf("died during sleep/eat\n");
			return ;
		}
		update_time(&program->curr_time);
	}
}

void	*philo_th(void *arg)
{
	t_program	*program;
	t_philo		philo;

	program = (t_program *)arg;
	start_philo(&philo, program);
	while (philo.state != DEAD)
	{
		update_curr_time(program);
		if (time_diff(program->curr_time, philo.last_eat) > program->time_die)
		{
			philo.state = DEAD;
			printf("died while thinking\n");
			break ;
		}
		if (philo.state == THINK /* && starving */)
		{
			/*grab forks*/
			philo.state = EAT;
			printf("%ldms %d is eating\n", update_curr_time(program), philo.id);
			timeout(program->time_eat, program, &philo);
		}
		else if(philo.state == EAT)
		{
			update_time(&philo.last_eat);
			philo.state = SLEEP;
			printf("%ldms %d is sleeping\n", update_curr_time(program), philo.id);
			timeout(program->time_sleep, program, &philo);
		}
		else if(philo.state == SLEEP)
		{
			philo.state = THINK;
			printf("%ldms %d is thinking\n", update_curr_time(program), philo.id);
		}
	}
	printf("%ldms %d died\n", update_curr_time(program), philo.id);
	// printf("last eat time %ld", time_diff(philo.last_eat, program->start_time));
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
		//// printf("%ldms\n", time_since_start(program));
		if (pthread_create(&program->threads[i], NULL, philo_th, program) != 0)
		{
			// printf("pthread_create() error");
			exit(1);
		}
	}
}

int	main(int argc, char **argv)
{
	t_program		program;
	int				i;

	update_time(&program.start_time);
	arg_parse(&program, argc, argv);
	pthread_mutex_init(&program.mutex, NULL);
	create_threads(&program);
	i = 0;
	while (i++ < program.phil_amt)
		pthread_join(program.threads[i], NULL);
}
