/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:41:21 by javi              #+#    #+#             */
/*   Updated: 2023/09/26 21:05:01 by javi             ###   ########.fr       */
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

//typedef s_project	t_project;

typedef struct s_philosopher
{
	int			id;
	int			flag_terminate;
	int			count_foods;
	int			has_forks;
	time_t		last_food;
	//t_project	*projects;
}	t_philosopher;

typedef struct s_project
{
	int				nbr_philosopher;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				number_of_foods;
	//t_philosopher	*philosopher;
}	t_project;

//src/utils.c
long		ft_atoi(const char *str);

//src/parser.c
t_project	*init_project(int argc, char **argv);

#endif