/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:29:56 by javi              #+#    #+#             */
/*   Updated: 2023/10/03 18:30:34 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

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
