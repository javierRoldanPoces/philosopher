/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:53:07 by javi              #+#    #+#             */
/*   Updated: 2023/09/30 14:18:47 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	ft_take_forks(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->fork_left);
	printf("%ld philo %d has taken a fork\n", (long)timestamp(philo->project), philo->id);
	pthread_mutex_lock(philo->fork);
	printf("%ld philo %d has taken a fork left\n",(long)timestamp(philo->project), philo->id);
}

void	ft_eat(t_philosopher *philo)
{
	printf("%ld philo %d is eat\n",(long)timestamp(philo->project), philo->id);
	pthread_mutex_lock(&philo->mute_lock);
	philo->count_foods++;
	philo->last_food = get_time();
	pthread_mutex_unlock(&philo->mute_lock);
	sleep_time(philo->project->time_to_eat, philo->project);
	pthread_mutex_unlock(&philo->fork_left);
	pthread_mutex_unlock(philo->fork);
}

void	ft_sleep(t_philosopher *philo)
{
	printf("%ld philo %d sleeping\n", (long)timestamp(philo->project), philo->id);
	sleep_time(philo->project->time_to_sleep, philo->project);
}

void	ft_think(t_philosopher *philo)
{
	printf("%ld philo %d Thinking\n", (long)timestamp(philo->project), philo->id);
}