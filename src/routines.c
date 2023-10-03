/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:12:17 by javi              #+#    #+#             */
/*   Updated: 2023/10/03 13:04:33 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	*ft_routine_checker(void *arg)
{
	t_project	*project;
	int			i;

	project = (t_project *)arg;
	while (!checker_finish(project))
	{
		i = 0;
		while (i < project->nbr_philo)
		{
			if (check_dead(&project->philo[i]))
			{
				pthread_mutex_lock(&project->mute_end_lock);
				printf("philo %d DEAD\n", project->philo[i].id);
				//printf("philo %d last_meal %ld tardo : %ld\n", project->philo[i].id, project->philo[i].last_food, get_time() - project->philo[i].last_food); AQUI ETABA EL DATA RACES
				pthread_mutex_unlock(&project->mute_end_lock);
				return (NULL);
			}
			else if (check_food(project))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}

void	*ft_routine_prueba(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
	{
		while (!checker_finish(philo->project))
		{
			ft_sleep(philo);
			ft_think(philo);
			ft_take_forks(philo);
			ft_eat(philo);
		}
	}
	else
	{
		while (!checker_finish(philo->project))
		{
			ft_take_forks(philo);
			ft_eat(philo);
			ft_sleep(philo);
			ft_think(philo);
		}
	}	
	return (NULL);
}
