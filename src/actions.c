/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:36:34 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/19 09:12:56 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	display(t_philo *philo, char *action)
{
	int	ms_current;

	pthread_mutex_lock(philo->m_display);
	ms_current = ((int) get_micro_sec(philo->time->micro_start) / 1000);
	if (ft_strcmp(action, MSG_EAT) == 0)
	{
		philo->ms_to_die = ms_current + philo->time->ms_to_die;
		// printf("fork)ms_current:%d ms_to_die:%d\n", ms_current, philo->ms_to_die);
	}
	if (ms_current >= philo->ms_to_die)
	{
		// printf("who:%d first_dead:%d(ms:%d, to_die:%d)\n", philo->num, philo->data->first_dead, ms_current, philo->ms_to_die);
		if (!philo->data->first_dead)
		{
			philo->data->first_dead = philo->num;
			philo->data->ms_current = ms_current;
		}
		pthread_mutex_unlock(philo->fork1);
		pthread_mutex_unlock(philo->fork2);
		pthread_mutex_unlock(philo->m_display);
		return ;
	}
	// printf("%d	%d	%s\t\t(status:%d)\n", ms_current, philo->num, action, philo->status);
	printf("%d	%d	%s\n", ms_current, philo->num, action);
	philo->status = ((philo->status + 1) % 5);
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
	usleep((useconds_t) (philo->time->ms_to_eat * 1000));
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
}
void	r_sleep(t_philo *philo)
{
	display(philo, MSG_SLEEP);
	usleep((useconds_t) (philo->time->ms_to_sleep * 1000));
}
void	r_think(t_philo *philo)
{
	display(philo, MSG_THINK);
	philo->count_to_eat -= 1;
}
