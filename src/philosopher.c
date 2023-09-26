/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:07:19 by javi              #+#    #+#             */
/*   Updated: 2023/09/26 21:05:24 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	main(int argc, char **argv)
{
	t_project	*project;

	if (argc < 5)
	{
		printf("error: Número de argumentos inválido.\n");
		return (1);
	}
	project = init_project(argc, argv);
	printf("nbr_philo-> %d \n", project->nbr_philosopher);
	printf("tie_to_die-> %ld \n", project->time_to_die);
	printf("tie_to_eat-> %ld \n", project->time_to_eat);
	printf("tie_to_sleep-> %ld \n", project->time_to_sleep);
	printf("number_of_FOOD-> %d \n", project->number_of_foods);

	return (0);
}
