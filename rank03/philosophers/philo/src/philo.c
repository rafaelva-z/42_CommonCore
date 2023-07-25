/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:02:08 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/25 16:49:48 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_philos(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philo_amt)
	{
		pthread_mutex_init(&program->philo[i]->mutex, NULL);
		program->philo[i]->id = i;
		program->philo[i]->program = program;
		program->philo[i]->state = THINK;
		program->philo[i]->fork = 1;
		update_time(&program->philo[i]->last_eat);
		print_msg(program, program->philo[i++]->id, MSG_BORN);
	}
}

int	death_check(t_philo	*philo, t_program *program)
{
	if (time_diff(program->curr_time, philo->last_eat) > program->time_die)
	{
		printf("id %dtime diff: %ld time die %ld\n", philo->id , time_diff(program->curr_time, philo->last_eat), program->time_die);
		print_death_msg(program, philo->id, philo->state);
		philo->state = DEAD;
		pthread_mutex_lock(&program->mutex);
		program->end_of_sim = 1;
		pthread_mutex_unlock(&program->mutex);
		return (1);
	}
	return (0);
}


//check if philo dies while sleeping/eating
void	philo_action(long int time, t_program *program, t_philo *philo)
{
	struct timeval	start_time;

	update_time(&start_time);
	update_time(&program->curr_time);
	while (time_diff(program->curr_time, start_time) < time)
	{
		if (death_check(philo, program))
			return ;
		update_time(&program->curr_time);
	}
}

int	grab_forks(t_program *program, t_philo *philo)
{
	if (program->philo_amt == 1)
		return (0);
	if (philo->id > 0)
	{
		pthread_mutex_lock(&philo->mutex);
		pthread_mutex_lock(&program->philo[philo->left_buddy]->mutex);
		if (philo->fork && program->philo[philo->left_buddy]->fork)
		{
			philo->fork--;
			program->philo[philo->left_buddy]->fork--;
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&program->philo[philo->left_buddy]->mutex);
			print_msg(program, philo->id, MSG_TAKE_FORK);
			return (2);
		}
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&program->philo[philo->left_buddy]->mutex);
	}
	else
	{
		pthread_mutex_lock(&program->philo[philo->left_buddy]->mutex);
		pthread_mutex_lock(&philo->mutex);
		if (philo->fork && program->philo[philo->left_buddy]->fork)
		{
			philo->fork--;
			program->philo[philo->left_buddy]->fork--;
			pthread_mutex_unlock(
				&program->philo[philo->left_buddy]->mutex);
			pthread_mutex_unlock(&philo->mutex);
			print_msg(program, philo->id, MSG_TAKE_FORK);
			return (2);
		}
		pthread_mutex_unlock(&program->philo[philo->left_buddy]->mutex);
		pthread_mutex_unlock(&philo->mutex);
	}
	return (0);
}

void	release_forks(t_program *program, t_philo *philo)
{
	if ((philo->id) % 2 == 0)
	{
		pthread_mutex_lock(&philo->mutex);
		pthread_mutex_lock(&program->philo[philo->left_buddy]->mutex);
		print_msg(program, philo->id, MSG_PUT_FORK);
		philo->fork++;
		(program->philo[philo->left_buddy]->fork)++;
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&program->philo[philo->left_buddy]->mutex);
	}
	else
	{
		pthread_mutex_lock(&program->philo[philo->left_buddy]->mutex);
		pthread_mutex_lock(&philo->mutex);
		print_msg(program, philo->id, MSG_PUT_FORK);
		philo->fork++;
		program->philo[philo->left_buddy]->fork++;
		pthread_mutex_unlock(&program->philo[philo->left_buddy]->mutex);
		pthread_mutex_unlock(&philo->mutex);
	}
}

void	*philo_th(void *arg)
{
	t_philo		*philo;
	t_program	*program;

	philo = (t_philo *)arg;
	program = philo->program;

	if (philo->id == 0)
		philo->left_buddy = program->philo[program->philo_amt - 1]->id;
	else
		philo->left_buddy = program->philo[philo->id - 1]->id;

	while (!program->end_of_sim)
	{
		update_curr_time(program);
		if (death_check(philo, program))
			break ;
		if (philo->state == THINK)
		{
			if (grab_forks(program, philo))
			{
				update_time(&philo->last_eat);
				philo->state = EAT;
				print_msg(program, philo->id, MSG_EAT);
				philo_action(program->time_eat, program, philo);
				release_forks(program, philo);
			}
		}
		else if(philo->state == EAT)
		{
			philo->state = SLEEP;
			print_msg(program, philo->id, MSG_SLEEP);
			philo_action(program->time_sleep, program, philo);
		}
		else if (philo->state == SLEEP)
		{
			philo->state = THINK;
			print_msg(program, philo->id, MSG_THINK);
			usleep(100);
		}
	}
	return (NULL);
}