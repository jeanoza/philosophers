/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:59:20 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/05/01 21:28:02 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(void *param)
{
	t_philo	*philo;

	philo = param;
	if (philo->eat_count == 0 && philo->num % 2 == 0)
		sleep_ajusted(philo->time->ms_to_eat / 1.3333);
	while (1)
	{
		pthread_mutex_lock(&philo->data->m_life);
		if (philo->data->first_dead)
		{
			pthread_mutex_unlock(&philo->data->m_life);
			return ;
		}
		pthread_mutex_unlock(&philo->data->m_life);
		if (philo->time->count_to_eat
			&& philo->time->count_to_eat == philo->eat_count)
			return ;
		r_take_fork(philo);
		r_eat(philo);
		r_sleep(philo);
		r_think(philo);
	}
}
