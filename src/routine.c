/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:59:20 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/22 12:30:11 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(void *param)
{
	t_philo	*philo;

	philo = param;
	while (!philo->data->first_dead)
	{
		if (philo->time->count_to_eat
			&& philo->time->count_to_eat == philo->eat_count)
			return ;
		if (philo->num % 2 == 0)
		{
			// sleep_ajusted(philo->time->ms_to_die, philo);
			usleep(100);
		}
		// philo->ms_current = get_time() - philo->time->ms_start;
		r_take_fork(philo);
		r_eat(philo);
		r_sleep(philo);
		r_think(philo);
	}
}