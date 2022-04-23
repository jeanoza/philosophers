/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:36:34 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/23 10:44:40 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->m_display);
	if (!philo->data->first_dead)
		printf("%lld	%d	%s(ms_to_die:%d)	(eat_count:%d) (count_to_eat:%d)\n", philo->ms_current, philo->num, action, philo->ms_to_die, philo->eat_count, philo->time->count_to_eat);
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
	philo->ms_to_die = philo->ms_current + philo->time->ms_to_die;
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
	philo->eat_count += 1;
}
