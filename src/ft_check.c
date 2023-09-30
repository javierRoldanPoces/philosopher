/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:17:08 by javi              #+#    #+#             */
/*   Updated: 2023/09/30 13:51:40 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

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

int	check_food(t_project *project)
{
	int	i;
	int	status;

	i = -1;
	status = 0;
	if (project->number_of_foods == 0)
		return (0);
	while (++i < project->nbr_philo)
	{
		pthread_mutex_lock(&project->philo[i].mute_lock);
		if (project->philo[i].count_foods < project->number_of_foods)
			status = 1;
		pthread_mutex_unlock(&project->philo[i].mute_lock);
	}
	if (status == 1)
	{
		pthread_mutex_lock(&project->mute_end_lock);
		project->flag_dead = 1;
		pthread_mutex_unlock(&project->mute_end_lock);
	}
	return (status);
}

int	check_dead(t_philosopher *philo)
{
	int	status;

	status = 0;
	pthread_mutex_lock(&philo->mute_lock);
	if (get_time() - philo->last_food > philo->project->time_to_die)
	{
		printf("philo %d DEAD\n", philo->id);
		status = 1;
	}
	pthread_mutex_unlock(&philo->mute_lock);
	if (status == 1)
	{
		pthread_mutex_lock(&philo->project->mute_end_lock);
		philo->project->flag_dead = 1;
		pthread_mutex_unlock(&philo->project->mute_end_lock);
	}
	return (status);
}
