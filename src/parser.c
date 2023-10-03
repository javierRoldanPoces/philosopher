/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:14:08 by javi              #+#    #+#             */
/*   Updated: 2023/10/03 13:07:40 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	ft_isdigit(int c)

{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

int	parse_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 5 || argc > 6)
		return (1);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_project	*init_project(int argc, char **argv)
{
	t_project	*project;

	project = (t_project *)malloc(sizeof(t_project));
	if (project == NULL)
	{
		free(project);
		return (NULL);
	}
	project->nbr_philo = ft_range_int((long)ft_atoi(argv[1]), ft_atoi_long(argv[1]));
	if (project->nbr_philo > 200)
		project->nbr_philo = 200;
	(project->time_to_die = ft_atoi_long(argv[2]));
	project->time_to_eat = ft_atoi_long(argv[3]);
	project->time_to_sleep = ft_atoi_long(argv [4]);
	if (argc > 5)
		project->number_of_foods = ft_range_int((long)ft_atoi(argv[5]), ft_atoi_long(argv[5]));
	else
		project->number_of_foods = -1;
	project->flag_dead = 0;
	project->start = get_time();
	if (project->nbr_philo < 1 || project->time_to_die < 0
		|| project->time_to_eat < 0 || project->time_to_sleep < 0
		|| project->number_of_foods == 0 || project->number_of_foods == -2)
	{
		free (project);
		return (NULL);
	}	
	if (project->time_to_eat == 0)
		project->time_to_eat = project->time_to_die / 5;
	if (project->time_to_sleep == 0)
		project->time_to_sleep = project->time_to_die / 5;
	pthread_mutex_init(&project->mute_end_lock, NULL);
	pthread_mutex_init(&project->mute_lock, NULL);
	return (project);
}

t_philosopher	*init_philo(t_project *project)
{
	int				i;
	t_philosopher	*philo;

	i = -1;
	philo = (t_philosopher *)malloc(sizeof(t_philosopher) * project->nbr_philo);
	if (philo == NULL)
		return (NULL);
	while (++i < project->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].flag_terminate = 0;
		philo[i].count_foods = 0;
		philo[i].last_food = get_time();
		pthread_mutex_init(&philo[i].fork_left, NULL);
		philo[i].fork = &philo[(i + 1) % project->nbr_philo].fork_left;
		philo[i].project = project;
		pthread_mutex_init(&philo[i].mute_lock, NULL);
	}
	return (philo);
}

int	thread_create(t_project *project)
{
	int			i;
	pthread_t	checker;

	i = -1;
	project->thread = (pthread_t *)malloc(sizeof(pthread_t) \
	* project->nbr_philo);
	if (project->thread == NULL)
		return (1);
	while (++i < project->nbr_philo)
	{
		if (pthread_create(&project->thread[i], NULL, ft_routine_prueba, \
			&project->philo[i]) != 0)
			return (1);
	}
	if (pthread_create(&checker, NULL, ft_routine_checker, \
		(void *)project) != 0)
		return (1);
	pthread_join(checker, NULL);
	return (0);
}
