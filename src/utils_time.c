/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <javi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:35:55 by javi              #+#    #+#             */
/*   Updated: 2023/09/30 14:17:51 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

/*
Calcula hora actual en milisegundos nos servira para comprobar tiempos , 
calculandola en distintos momentos y comparandola
*/

time_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec / 1000);
}

/*
Funcion para esperar que acaben las ditintas acciones 
*/
void	sleep_time(time_t tm, t_project *project)
{
	time_t	start;

	start = get_time();
	while (get_time() - start < tm &&  !checker_finish(project))
		usleep(1000);
}

/*
Funcion para ir mostrando por pantalla el tiempo  transcurrido desde que 
inicio la ejecución hasta q se realiza la acción (se imprime)
*/
time_t	timestamp(t_project *project)
{
	return (get_time() - project->start);
}