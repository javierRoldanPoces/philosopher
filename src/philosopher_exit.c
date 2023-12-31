/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:29:03 by javier            #+#    #+#             */
/*   Updated: 2023/10/03 18:29:48 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	join_threads(t_project *project)
{
	int	i;

	i = -1;
	while (++i < project->nbr_philo)
		pthread_join(project->thread[i], NULL);
}

void	destroy_mutex(t_project *project)
{
	int	i;

	i = 0;
	while (i < project->nbr_philo)
	{
		pthread_mutex_destroy(&project->philo[i].mute_lock);
		pthread_mutex_destroy(&project->philo[i].fork_left);
		i++;
	}
	pthread_mutex_destroy(&project->mute_lock);
	pthread_mutex_destroy(&project->mute_end_lock);
}

void	free_project(t_project *project)
{
	free(project->philo);
	free(project->thread);
	free(project);
}
