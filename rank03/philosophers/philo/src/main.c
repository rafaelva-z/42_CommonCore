/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:49:02 by rvaz              #+#    #+#             */
/*   Updated: 2023/07/19 21:59:39 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	arg_check(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 6)
	{
		if (argc > 6)
			printf("[philo] ERROR - Too many arguments\n");
		else if (argc < 6)
			printf("[philo] ERROR - Not enough arguments\n");
		exit(0);
	}
	i = -1;
	j = 0;
	while (argv[++j][++i])
	{
		if (!ft_isdigit(argv[j][i]))
		{
			printf("[philo] ERROR - invalid charcter in args\n");
			exit(0);
		}
	}
}

void	*thread_1(void *arg)
{
	int phil_num;

	phil_num = *(int *)arg;
	printf("-Philosopher %d\n", phil_num);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t		thid;
	struct timeval	start_time;
	struct timeval	curr_time;
	int				phil_num;
	int				i;

	gettimeofday(&start_time, NULL);
	arg_check(argc, argv);
	phil_num = ft_atoi(argv[1]);
	i = 0;
	while (i++ < phil_num)
	{
		gettimeofday(&curr_time, NULL);
		printf("%ldms -", curr_time.tv_usec - start_time.tv_usec);
		if (pthread_create(&thid, NULL, thread_1, &i) != 0)
		{
			perror("pthread_create() error");
			exit(1);
		}
		pthread_join(thid, NULL);
	}
}
