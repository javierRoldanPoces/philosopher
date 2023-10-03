/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:53:07 by javi              #+#    #+#             */
/*   Updated: 2023/10/03 19:19:22 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	ft_take_forks(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->fork_left);
	printf("%ld ms %d has taken a fork\n", \
	(long)timestamp(philo->project), philo->id);
	if (philo->project->nbr_philo == 1)
	{
		pthread_mutex_lock(&philo->project->mute_end_lock);
		usleep(philo->project->time_to_die * 1000);
		philo->project->flag_dead = 1;
		pthread_mutex_unlock(&philo->project->mute_end_lock);
		pthread_mutex_unlock(&philo->fork_left);
		printf("%ld %d \033[31mdead \033[0m \n", (long)timestamp(philo->project), \
		philo->id);
		return ;
	}
	pthread_mutex_lock(philo->fork);
	printf("%ld ms %d has taken a fork left\n", \
	(long)timestamp(philo->project), philo->id);
}

void	ft_eat(t_philosopher *philo)
{
	if (philo->project->nbr_philo == 1)
		return ;
	printf("%ld ms %d is eat\n", (long)timestamp(philo->project), philo->id);
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
	if (philo->project->nbr_philo == 1)
		return ;
	printf("%ld ms %d sleeping\n", (long)timestamp(philo->project), philo->id);
	sleep_time(philo->project->time_to_sleep, philo->project);
}

void	ft_think(t_philosopher *philo)
{
	if (philo->project->nbr_philo == 1)
		return ;
	printf("%ld ms %d is thinking\n", (long)timestamp(philo->project), \
	philo->id);
}
