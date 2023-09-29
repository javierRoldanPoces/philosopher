/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:12:17 by javi              #+#    #+#             */
/*   Updated: 2023/09/29 13:27:35 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	ft_take_forks(t_philosopher *philo)
{
	pthread_mutex_lock(philo->fork);
	printf("%ld philo %d has taken a fork\n", (long)timestamp(philo->project), philo->id);
	pthread_mutex_lock(&philo->fork_left);
	printf("%ld philo %d has taken a fork\n",(long)timestamp(philo->project), philo->id);
	philo->has_forks = 1;
}

void	ft_eat(t_philosopher *philo)
{
	printf("%ld philo %d is eat\n",(long)timestamp(philo->project), philo->id);
	philo->count_foods++;
	philo->last_food = get_time();
	sleep_time(philo->project->time_to_eat, philo);
	pthread_mutex_unlock(&philo->fork_left);
	pthread_mutex_unlock(philo->fork);
	philo->nbr_foods++;
}

void	ft_sleep(t_philosopher *philo)
{
	printf("%ld philo %d sleeping\n", (long)timestamp(philo->project), philo->id);
	sleep_time(philo->project->time_to_sleep, philo);
}

void	ft_think(t_philosopher *philo)
{
	printf("%ld philo %d Thinking\n", (long)timestamp(philo->project), philo->id);
}

int	checker_finish(t_project *project)
{
	int	finish;

	finish = 0;
	pthread_mutex_lock(&project->mute_end_lock);
	if (project->flag_dead == 1)
		finish = 1;
	pthread_mutex_unlock(&project->mute_end_lock);
	return (finish);
}

void	*ft_routine_prueba(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
	{
		while (philo->flag_terminate == 0)
		{
			ft_take_forks(philo);
			ft_eat(philo);
			ft_sleep(philo);
			ft_think(philo);
			philo->flag_terminate = 1;// sirve de pruea para ver si se termina el hilo	
		}
	}
	else
	{
		while (philo->flag_terminate == 0)
		{
			ft_sleep(philo);
			ft_think(philo);
			ft_take_forks(philo);
			ft_eat(philo);
			philo->flag_terminate = 1; // sirve de pruea para ver si se termina el hilo		

		}
	}	
	return (NULL);
}
