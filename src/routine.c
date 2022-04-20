/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:59:20 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/20 07:46:35 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(void *param)
{
	t_philo	*philo;
	
	philo = param;
	while (philo->count_to_eat > 0 && !philo->data->first_dead)
	{
		if (philo->status == 0)
		{
			if (philo->num % 2 == 0
				&& philo->time->count == philo->count_to_eat)
				usleep(philo->time->ms_to_eat * 1000);
			r_take_fork(philo);
		}
		else if (philo->status == 2)
			r_eat(philo);
		else if (philo->status == 3)
			r_sleep(philo);
		else if (philo->status == 4)
			r_think(philo);
	}
}