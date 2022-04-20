/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:36:34 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/20 23:25:44 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	display(t_philo *philo, char *action)
{

	pthread_mutex_lock(philo->m_display);
	philo->ms_current = get_micro_sec(philo->time->micro_start);
	if (philo->ms_current >= philo->ms_to_die)
	{
		if (!philo->data->first_dead)
		{
			philo->data->first_dead = philo->num;
			philo->data->ms_current = philo->ms_current;
		}
		pthread_mutex_unlock(philo->fork1);
		pthread_mutex_unlock(philo->fork2);
		pthread_mutex_unlock(philo->m_display);
		return ;
	}
	printf("%lld	%d	%s\n", philo->ms_current, philo->num, action);
	pthread_mutex_unlock(philo->m_display);
}

void	r_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	pthread_mutex_lock(philo->fork2);
	display(philo, MSG_FORKS);
	display(philo, MSG_FORKS);
}

void	r_eat(t_philo *philo)
{
	display(philo, MSG_EAT);
	usleep((useconds_t)(philo->time->ms_to_eat * 1000));
	philo->ms_to_die = philo->ms_current + philo->time->ms_to_die;
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
}

void	r_sleep(t_philo *philo)
{
	display(philo, MSG_SLEEP);
	usleep((useconds_t)(philo->time->ms_to_sleep * 1000));
}

void	r_think(t_philo *philo)
{
	display(philo, MSG_THINK);
	philo->count_to_eat -= 1;
}
