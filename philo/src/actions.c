/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:36:34 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/05/05 15:22:44 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->data->m_life);
	philo->ms_current = get_time() - philo->time->ms_start;
	if (!(philo->data->first_dead || philo->data->all_ate))
	{
		printf("%lld	%d	%s.\n", philo->ms_current, philo->num, action);
		if (ft_strcmp(action, MSG_EAT) == 0)
		{
			philo->ms_to_die = philo->ms_current + philo->time->ms_to_die;
			philo->eat_count += 1;
		}
	}
	pthread_mutex_unlock(&philo->data->m_life);
}

void	r_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_forks[philo->i_fork1]);
	pthread_mutex_lock(&philo->data->m_forks[philo->i_fork2]);
	display(philo, MSG_FORKS);
	display(philo, MSG_FORKS);
}

void	r_eat(t_philo *philo)
{
	display(philo, MSG_EAT);
	sleep_ajusted(philo->time->ms_to_eat);
	pthread_mutex_unlock(&philo->data->m_forks[philo->i_fork1]);
	pthread_mutex_unlock(&philo->data->m_forks[philo->i_fork2]);
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
