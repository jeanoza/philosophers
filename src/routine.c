/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:59:20 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/19 09:12:25 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//TODO:add philo->status to unutil operation
//ex: if (!philo->data->first_dead && philo->status == TO_EAT)
void	routine(void *param)
{
	t_philo	*philo;
	
	philo = param;
	while (philo->count_to_eat > 0)
	{
		if (!philo->data->first_dead)
		{
			if (philo->status == 0)
				r_take_fork(philo);
			else if (philo->status == 2)
				r_eat(philo);
			else if (philo->status == 3)
				r_sleep(philo);
			else if (philo->status == 4)
				r_think(philo);
		}
		else
			return ;
	}
}