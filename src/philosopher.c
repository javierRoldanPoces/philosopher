/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:07:19 by javi              #+#    #+#             */
/*   Updated: 2023/09/28 17:53:08 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	print_philo(t_philosopher *philo, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("id philo %d\n", philo[i].id);
		i++;
	}
}

void	print_project(t_project *project)
{
	printf("nbr_philo-> %d \n", project->nbr_philo);
	printf("tie_to_die-> %ld \n", project->time_to_die);
	printf("tie_to_eat-> %ld \n", project->time_to_eat);
	printf("tie_to_sleep-> %ld \n", project->time_to_sleep);
	printf("number_of_FOOD-> %d \n", project->number_of_foods);
	printf("PHILOSOPHER\n");
	print_philo(project->philo, project->nbr_philo);
}

int	main(int argc, char **argv)
{
	t_project		*project;

	if (argc < 5)
		return (printf("error: Número de argumentos inválido.\n"), 1);
	project = init_project(argc, argv);
	project->philo = init_philo(project);
	thread_create(project);
	//print_project(project);
	return (0);
}
