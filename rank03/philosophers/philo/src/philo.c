/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:02:08 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/24 17:41:40 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_philos(t_program *program)
{
	int	i;

	i = 0;
	while(i < program->philo_amt)
	{
		pthread_mutex_init(&program->philo[i]->mutex, NULL);
		program->philo[i]->id = i;
		program->philo[i]->program = program;
		program->philo[i]->state = THINK;
		program->philo[i++]->fork = 1;
	}
	i = 0;
	while (i < program->philo_amt)
	{
		update_time(&program->philo[i]->last_eat);
		print_msg(program, program->philo[i++]->id, MSG_BORN);
	}
}

int	death_check(t_philo	*philo, t_program *program)
{
	if (time_diff(program->curr_time, philo->last_eat) > program->time_die)
	{
		print_death_msg(program, philo->id, philo->state);
		philo->state = DEAD;
		pthread_mutex_lock(&program->mutex);
		program->philo_alive -= 1;
		program->end_of_sim = 1;
		pthread_mutex_unlock(&program->mutex);
		return (1);
	}
	return (0);
}


//check if philo dies while sleeping/eating
void	timeout(long int time, t_program *program, t_philo *philo)
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
		pthread_mutex_lock(&program->philo[philo->id - 1]->mutex);
		usleep(100);
		//printf("%ldss %d shoulda stay or shouda go?  \n", update_curr_time(program), philo->id);

		if (philo->fork && program->philo[philo->id - 1]->fork)
		{
			philo->fork--;
			program->philo[philo->id - 1]->fork--;
			print_msg(program, philo->id, MSG_TAKE_FORK);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&program->philo[philo->id - 1]->mutex);
			return (2);
		}
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&program->philo[philo->id - 1]->mutex);
		//printf("%ldss %d nah im out bruv\n", update_curr_time(program), philo->id);

	}
	else
	{
		pthread_mutex_lock(&program->philo[program->philo_amt - 1]->mutex);
		pthread_mutex_lock(&philo->mutex);
		usleep(100);
		if (philo->fork && program->philo[program->philo_amt - 1]->fork)
		{
			philo->fork--;
			program->philo[program->philo_amt - 1]->fork--;
			print_msg(program, philo->id, MSG_TAKE_FORK);
			pthread_mutex_unlock(
				&program->philo[program->philo_amt - 1]->mutex);
			pthread_mutex_unlock(&philo->mutex);
			return (2);
		}
		pthread_mutex_unlock(&program->philo[program->philo_amt - 1]->mutex);
		pthread_mutex_unlock(&philo->mutex);
	}
	return (0);
}

void	release_forks(t_program *program, t_philo *philo)
{
	if (philo->id > 0)
	{
		pthread_mutex_lock(&philo->mutex);
		pthread_mutex_lock(&program->philo[philo->id - 1]->mutex);
		philo->fork++;
		(program->philo[philo->id - 1]->fork)++;
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&program->philo[philo->id - 1]->mutex);
		print_msg(program, philo->id, MSG_PUT_FORK);
	}
	else
	{
		printf("%ldms %d  shoulda give this back? %d \n", update_curr_time(program),philo->id, program->philo_amt - 1);
		pthread_mutex_lock(&program->philo[program->philo_amt - 1]->mutex);
		printf("%ldms %d  this guys mutex is faain\n",  update_curr_time(program), philo->id);
		pthread_mutex_lock(&philo->mutex);
		printf("%ldms %d  YO WHO TOUCH MY MUTEX?\n",  update_curr_time(program), philo->id);
		philo->fork++;
		program->philo[program->philo_amt - 1]->fork++;
		pthread_mutex_unlock(&program->philo[program->philo_amt - 1]->mutex);
		pthread_mutex_unlock(&philo->mutex);
		print_msg(program, philo->id, MSG_PUT_FORK);
	}
}

void	*philo_th(void *arg)
{
	t_program	*program;
	t_philo		*philo;

	program = (t_program *)arg;
	pthread_mutex_lock(&program->mutex);
	philo = program->philo[program->philo_alive++];
	pthread_mutex_unlock(&program->mutex);
	while (!program->end_of_sim)
	{
		update_curr_time(program);
		if (death_check(philo, program))
			break ;
		if (philo->state == THINK)
		{
			printf("%ldms %d a guys gotta eat\n",  update_curr_time(program), philo->id);
			if (grab_forks(program, philo))
			{
				philo->state = EAT;
				update_time(&philo->last_eat);
				print_msg(program, philo->id, MSG_EAT);
				timeout(program->time_eat, program, philo);
				print_msg(program, philo->id, "YO DONE EATING");
				release_forks(program, philo);
			}
		}
		else if(philo->state == EAT)
		{
			philo->state = SLEEP;
			print_msg(program, philo->id, MSG_SLEEP);
			timeout(program->time_sleep, program, philo);
		}
		else if (philo->state == SLEEP)
		{
			philo->state = THINK;
			print_msg(program, philo->id, MSG_THINK);
		}
	}
	return (NULL);
}