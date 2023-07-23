/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:42:07 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/23 21:06:59 by rvaz             ###   ########.fr       */
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
	int				philo_alive;
	long int		time_die;
	long int		time_eat;
	long int		time_sleep;
	int				eat_amt;
	struct timeval	start_time;
	struct timeval	curr_time;
	pthread_mutex_t	mutex;
}	t_program;

struct s_philo
{
	t_program		*program;
	int				id;
	int				state;
	struct timeval	last_eat;
	int				fork;
	pthread_mutex_t	mutex;
};

//	Time
long int	time_from_start(t_program program);
long int	time_diff(struct timeval time1, struct timeval time2);
void		update_time(struct timeval *time);
long int	update_curr_time(t_program *program);
//	Utils
void		arg_parse(t_program *program, int argc, char **argv);
int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
//	Threads
void		create_threads(t_program *program);
void		*philo_th(void *arg);
//	Print
void		print_msg(t_program *program, int id, char *str);
void		print_death_msg(t_program *program, int id, int state);
//	Philo
void		start_philo(t_philo *philo, t_program *program);
int			death_check(t_philo	*philo, t_program *program);
void		timeout(long int time, t_program *program, t_philo *philo);
int			grab_forks(t_program *program, t_philo *philo);
void		release_forks(t_program *program, t_philo *philo);

#endif
