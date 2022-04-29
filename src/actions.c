/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:36:34 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/23 21:37:40kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->m_display);
	philo->ms_current = get_time() - philo->time->ms_start;
	if (ft_strcmp(action, MSG_EAT) == 0)
	{
		philo->ms_to_die = philo->ms_current + philo->time->ms_to_die;
		philo->eat_count += 1;
	}
	if (philo->data->first_dead)
	// if (philo->is_dead)
	{
		pthread_mutex_unlock(philo->m_fork1);
		pthread_mutex_unlock(philo->m_fork2);
		pthread_mutex_unlock(philo->m_display);
		pthread_mutex_unlock(philo->m_life);
		return ;
	}
	else
		printf("%lld	%d	%s\n", philo->ms_current, philo->num, action);
	pthread_mutex_unlock(philo->m_display);
}

void	r_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->m_fork1);
	pthread_mutex_lock(philo->m_fork2);
	display(philo, MSG_FORKS);
	display(philo, MSG_FORKS);
}

void	r_eat(t_philo *philo)
{
	display(philo, MSG_EAT);
	sleep_ajusted(philo->time->ms_to_eat);
	pthread_mutex_unlock(philo->m_fork1);
	pthread_mutex_unlock(philo->m_fork2);
}

void	r_sleep(t_philo *philo)
{
	display(philo, MSG_SLEEP);
	sleep_ajusted(philo->time->ms_to_sleep);
}

void	r_think(t_philo *philo)
{
	display(philo, MSG_THINK);
}
