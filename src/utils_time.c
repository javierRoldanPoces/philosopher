/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:35:55 by javi              #+#    #+#             */
/*   Updated: 2023/10/02 12:16:08 by javier           ###   ########.fr       */
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
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/*
Funcion para esperar que acaben las ditintas acciones 
*/
void	sleep_time(time_t tm, t_project *project)
{
	time_t	start;

	start = get_time();
	if (tm != 0)
	{
		while (get_time() - start < tm && !checker_finish(project))
			usleep(1000);
	}	
}

/*
Funcion para ir mostrando por pantalla el tiempo  transcurrido desde que 
inicio la ejecución hasta q se realiza la acción
*/
time_t	timestamp(t_project *project)
{
	return (get_time() - project->start);
}
