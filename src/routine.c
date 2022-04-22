/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:59:20 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/23 00:20:23 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(void *param)
{
	t_philo	*philo;

	philo = param;
	// while (!philo->data->first_dead)
	while (philo->data->ms_current < philo->ms_to_die)
	{
		if (philo->time->count_to_eat
			&& philo->time->count_to_eat == philo->eat_count)
			return ;
		r_take_fork(philo);
		r_eat(philo);
		r_sleep(philo);
		r_think(philo);
	}
}