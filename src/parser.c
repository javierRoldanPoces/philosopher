/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:14:08 by javi              #+#    #+#             */
/*   Updated: 2023/09/27 19:29:31 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

t_project	*init_project(int argc, char **argv)
{
	t_project	*project;

	project = (t_project *)malloc(sizeof(t_project));
	if (project == NULL)
		return (NULL);
	project->nbr_philo = (int)ft_atoi(argv[1]);
	project->time_to_die = ft_atoi(argv[2]);
	project->time_to_eat = ft_atoi(argv[3]);
	project->time_to_sleep = ft_atoi(argv [4]);
	if (argc > 5)
		project->number_of_foods = (int)ft_atoi(argv[5]);
	else
		project->number_of_foods = 0;
	if (project->nbr_philo < 1 || project->time_to_die < 1
		|| project->time_to_eat < 1 || project->time_to_sleep < 1)
		return (NULL);
	thread_create(project);
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
		philo[i].id = i;
		philo[i].flag_terminate = 0;
		philo[i].count_foods = 0;
		philo[i].has_forks = 0;
	}
	return (philo);
}

void	*ft_routine_prueba(void *arg)
{
	int	i;

	//i = *((int *)arg);
	(void)arg;
	i = 1;
	printf("Hilo creado correctamente: Soy el hilo %d\n", i);
	return (NULL);
}

int	thread_create(t_project *project)
{
	int			i;

	i = -1;
	project->thread = (pthread_t *)malloc(sizeof(pthread_t) * project->nbr_philo);
	if (project->thread == NULL)
		return (1);
	while (++i < project->nbr_philo)
	{
		if (pthread_create(&project->thread[i], NULL, ft_routine_prueba, NULL) != 0)
			return (1);
		pthread_join(project->thread[i], NULL);
	}
	return (0);
}
