/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:14:08 by javi              #+#    #+#             */
/*   Updated: 2023/09/26 21:05:11 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

t_project	*init_project(int argc, char **argv)
{
	t_project	*project;

	(void)argc;
	project = (t_project *)malloc(sizeof(t_project));
	if (project == NULL)
		return (NULL);
	printf("0\n");
	project->nbr_philosopher = (int)ft_atoi(argv[1]);
	printf("1\n");
	project->time_to_die = ft_atoi(argv[2]);
	project->time_to_eat = ft_atoi(argv[3]);
	project->time_to_sleep = ft_atoi(argv [4]);
	if (argc > 5)
		project->number_of_foods = (int)ft_atoi(argv[5]);
	else
		project->number_of_foods = 0;
	return (project);
}
