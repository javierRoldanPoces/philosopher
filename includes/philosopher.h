/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:41:21 by javi              #+#    #+#             */
/*   Updated: 2023/09/29 13:28:05 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_project	t_project;

typedef struct s_philosopher
{
	int					id;
	int					flag_terminate;
	int					count_foods;
	int					has_forks;
	int					nbr_foods;
	time_t				last_food;
	pthread_mutex_t		fork_left;
	pthread_mutex_t		*fork;
	t_project			*project;
}	t_philosopher;

typedef struct s_project
{
	int				nbr_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				number_of_foods;
	int				flag_dead;
	int				flag_end;
	time_t			start;
	t_philosopher	*philo;
	pthread_t		*thread;
	pthread_mutex_t		mute_lock;
	pthread_mutex_t		mute_end_lock;
}	t_project;

//src/utils.c
long			ft_atoi(const char *str);

//src/parser.c
t_project		*init_project(int argc, char **argv);
t_philosopher	*init_philo(t_project *project);
int				thread_create(t_project *project);

//src/utils_time.c
time_t			get_time(void);
void			sleep_time(time_t tm, t_philosopher *philo);
time_t			timestamp(t_project *project);

//src/rourines.c
void			*ft_routine_prueba(void *arg);

//src/ft_check.c
//void			*routine_check(void *arg);



#endif