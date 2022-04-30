/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:59:20 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/30 14:51:46 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	current_ate(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->time->count_to_eat == 0)
		return (0);
	if (philo->eat_count != philo->time->count_to_eat)
		return (0);
	return (1);
}

void	routine(void *param)
{
	t_philo	*philo;

	philo = param;
	while (!philo->data->first_dead)
	// while (!philo->is_dead)
	{
		if (philo->time->count_to_eat
			&& philo->time->count_to_eat == philo->eat_count)
			return ;
		// if (current_ate(philo))
		// 	return ;
		if (philo->eat_count == 0 && philo->num % 2 == 0)
			sleep_ajusted(philo->time->ms_to_eat);
		r_take_fork(philo);
		r_eat(philo);
		r_sleep(philo);
		// r_think(philo);
	}
}
