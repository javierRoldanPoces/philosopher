/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:41:21 by javi              #+#    #+#             */
/*   Updated: 2023/09/27 19:16:15 by javi             ###   ########.fr       */
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

typedef struct s_philosopher
{
	int			id;
	int			flag_terminate;
	int			count_foods;
	int			has_forks;
	time_t		last_food;
}	t_philosopher;

typedef struct s_project
{
	int				nbr_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				number_of_foods;
	int				flag_dead;
	t_philosopher	*philo;
	pthread_t		*thread;
}	t_project;

//src/utils.c
long			ft_atoi(const char *str);

//src/parser.c
t_project		*init_project(int argc, char **argv);
t_philosopher	*init_philo(t_project *project);
int				thread_create(t_project *project);

#endif