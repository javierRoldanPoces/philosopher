/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:41:21 by javi              #+#    #+#             */
/*   Updated: 2023/10/03 18:30:51 by javi             ###   ########.fr       */
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
	time_t				last_food;
	pthread_mutex_t		fork_left;
	pthread_mutex_t		*fork;
	pthread_mutex_t		mute_lock;
	t_project			*project;
}	t_philosopher;

typedef struct s_project
{
	int					nbr_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					number_of_foods;
	int					flag_dead;
	time_t				start;
	t_philosopher		*philo;
	pthread_t			*thread;
	pthread_mutex_t		mute_lock;
	pthread_mutex_t		mute_end_lock;
}	t_project;

//src/utils.c
int				ft_isdigit(int c);
long			ft_atoi(const char *str);
long			ft_atoi_long(const char *str);
int				ft_range_int(long a, long b);

//src/parser.c
int				parse_arg(int argc, char **argv);
t_project		*init_project(int argc, char **argv);
t_philosopher	*init_philo(t_project *project);

//src/thread.c
int				thread_create(t_project *project);

//src/utils_time.c
time_t			get_time(void);
void			sleep_time(time_t tm, t_project *project);
time_t			timestamp(t_project *project);

//src/routines.c
void			*ft_routine_prueba(void *arg);
void			*ft_routine_checker(void *arg);

//src/ft_check.c
int				checker_finish(t_project *project);
int				check_food(t_project *project);
int				check_dead(t_philosopher *philo);

//src/actions.c
void			ft_take_forks(t_philosopher *philo);
void			ft_eat(t_philosopher *philo);
void			ft_sleep(t_philosopher *philo);
void			ft_think(t_philosopher *philo);

//src/philosopher_exit.c

void			join_threads(t_project *project);
void			destroy_mutex(t_project *project);
void			free_project(t_project *project);

#endif