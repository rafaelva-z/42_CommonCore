/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:42:07 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/21 21:20:19 by rvaz             ###   ########.fr       */
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

# define EAT	1;
# define THINK	2;
# define SLEEP	3;

typedef struct s_program
{
	pthread_t		*threads;
	int				phil_amt;
	int				phil_created;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				eat_amt;
	struct timeval	start_time;
	struct timeval	curr_time;
	pthread_mutex_t	mutex;
	/*sem_t			*print;
	sem_t			*eat; */
}	t_program;

typedef struct s_philo
{
	t_program		*program;
	int				id;
	int				state;
	struct timeval	last_eat;
	int				isdead;
	sem_t			forks;

}	t_philo;

void	arg_parse(t_program *program, int argc, char **argv);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);

#endif
