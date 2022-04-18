/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:59:20 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/18 22:03:23 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//TODO: update each philos ms_current in display && put is_dead
//philo->ms_current && philo->is_dead
int		someone_dead(t_philo *philo)
{
	int	ms_current;
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		ms_current = (int) get_micro_sec(philo->time->micro_start) / 1000;
		if (ms_current >= philo->ms_to_die)
		{
			printf("%d	%d	has been died\n", ms_current, philo->num);
			return (1);
		}
		++i;
	}

	return (0);
}
void	routine(void *param)
{
	t_philo	*philo;
	
	philo = param;
	//FIXME:this trigger have to remove | change with time
	while (philo->count_to_eat > 0)
	{
		if (!someone_dead(philo))
		{
			r_take_fork(philo);
			r_eat(philo);
			r_sleep(philo);
			r_think(philo);
		}
		else
			return ;
	}
}