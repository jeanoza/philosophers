/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:36:34 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/22 12:42:42 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->m_display);
	philo->ms_current = get_time() - philo->time->ms_start;
	if (philo->data->first_dead || philo->ms_current >= philo->ms_to_die)
	{
		//FIXME: this dead timing has to change
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
	// printf("%lld	%d	%s		(ms_to_die:%d, ec:%d)\n", philo->ms_current, philo->num, action, philo->ms_to_die, philo->eat_count);
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
	philo->ms_to_die = philo->ms_current + philo->time->ms_to_die;
	sleep_ajusted(philo->time->ms_to_eat, philo);
	// sleep_ajusted(philo->time->ms_to_eat);
	// usleep(philo->time->ms_to_eat * 1000);
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
}

void	r_sleep(t_philo *philo)
{
	display(philo, MSG_SLEEP);
	sleep_ajusted(philo->time->ms_to_sleep, philo);
	// // sleep_ajusted(philo->time->ms_to_sleep);
	// usleep(philo->time->ms_to_sleep * 1000);
}

void	r_think(t_philo *philo)
{
	display(philo, MSG_THINK);
	philo->eat_count += 1;
}
