/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:59:20 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/20 23:09:05 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(void *param)
{
	t_philo	*philo;

	philo = param;
	// while (philo->count_to_eat > 0 && !philo->data->first_dead)
	while (philo->ms_current < philo->ms_to_die)
	{
		if (philo->count_to_eat == 0)
			return ;
		if (philo->num % 2 == 0
			&& philo->time->count == philo->count_to_eat)
			usleep(philo->time->ms_to_eat * 1000 / 1.3333);
		r_take_fork(philo);
		r_eat(philo);
		r_sleep(philo);
		r_think(philo);
	}
}