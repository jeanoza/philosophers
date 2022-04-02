/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:34:39 by kychoi            #+#    #+#             */
/*   Updated: 2022/04/02 22:19:15 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	case_odd(t_philo *philo)
{
	if (philo->forks[philo->i] == 1 && philo->forks[philo->i + 1] == 1)
		take_fork(philo);
		
}
static void	case_even(t_philo *philo)
{
	if (philo->forks[philo->i] == 1 && philo->forks[philo->i + 1] == 1)
		take_fork(philo);
}

void	*algo(void *param)
{

	pthread_mutex_lock(&((t_philo *) param)->mutex);
	//TODO: put algo philo(odd/even)
	if (((t_philo *) param)->nb_philos % 2 == 1)
		case_odd(((t_philo *) param));
	else
		case_even(((t_philo *) param));
	++((t_philo *) param)->i;
	pthread_mutex_unlock(&((t_philo *) param)->mutex);
	return (0);
}
