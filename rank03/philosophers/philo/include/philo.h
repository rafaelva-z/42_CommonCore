/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:42:07 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/25 16:29:09 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

// Philosopher states
# define DEAD	0
# define EAT	1
# define THINK	2
# define SLEEP	3

// Messages

# define MSG_EAT		"is eating"
# define MSG_SLEEP		"is sleeping"
# define MSG_THINK		"is thinking"
# define MSG_TAKE_FORK	"has taken the forks"
# define MSG_PUT_FORK	"has put down the forks"
# define MSG_BORN		"is born"
# define MSG_DEAD		"died"
# define MSG_DEAD_EAT	"died while eating"
# define MSG_DEAD_THINK	"died while thinking"
# define MSG_DEAD_SLEEP	"died while sleeping"

typedef struct s_philo	t_philo;

typedef struct s_program
{
	pthread_t		*threads;
	t_philo			**philo;
	int				philo_amt;
	long int		time_die;
	long int		time_eat;
	long int		time_sleep;
	int				eat_amt;
	struct timeval	start_time;
	struct timeval	curr_time;
	pthread_mutex_t	mutex;
	int				end_of_sim;
}	t_program;

struct s_philo
{
	t_program		*program;
	int				id;
	int				state;
	struct timeval	last_eat;
	int				fork;
	pthread_mutex_t	mutex;
	int				left_buddy;
};

//	Time
long int	time_from_start(t_program program);
long int	time_diff(struct timeval time1, struct timeval time2);
void	update_time(struct timeval *time);
long int	update_curr_time(t_program *program);
//	Utils
int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
//	Threads
void		create_threads(t_program *program);
void		*philo_th(void *arg);
//	Print
void		print_msg(t_program *program, int id, char *str);
void		print_death_msg(t_program *program, int id, int state);
//	Program
void		start_program(t_program *program, int argc, char **argv);
void		end_program(t_program *program);
//	Philo
void		start_philos(t_program *program);
int			death_check(t_philo	*philo, t_program *program);
void		philo_action(long int time, t_program *program, t_philo *philo);
int			grab_forks(t_program *program, t_philo *philo);
void		release_forks(t_program *program, t_philo *philo);
//	Memory
void		alloc_philos(t_program *program);
void		free_philos(t_program *program);

#endif
