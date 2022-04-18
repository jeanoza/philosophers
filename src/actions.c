/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:36:34 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/18 14:47:49 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display(t_philo *philo, char *action)
{
	int	ms_current;

	pthread_mutex_lock(philo->m_display);
	ms_current = ((int) get_micro_sec(philo->time->micro_start) / 1000);
	printf("%d	%d	%s\n", ms_current, philo->num, action);
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
	// pthread_mutex_lock(philo->m_eat);
	display(philo, MSG_EAT);
	usleep((useconds_t) (philo->time->ms_to_eat * 1000));
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	// pthread_mutex_unlock(philo->m_eat);
}
void	r_sleep(t_philo *philo)
{
	// pthread_mutex_lock(philo->m_sleep);
	display(philo, MSG_SLEEP);
	usleep((useconds_t) (philo->time->ms_to_sleep * 1000));
	// pthread_mutex_unlock(philo->m_sleep);
}
void	r_think(t_philo *philo)
{
	// pthread_mutex_unlock(philo->m_think);
	display(philo, MSG_THINK);
	philo->count_to_eat -= 1;
	// pthread_mutex_unlock(philo->m_think);
}
