/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:36:34 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/14 11:09:49 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	r_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	pthread_mutex_lock(philo->fork2);
	pthread_mutex_lock(philo->display);
	printf("%d	%d	has taken a fork...\n", get_ms(philo->time->ms_start), philo->num);
	printf("%d	%d	has taken a fork...\n", get_ms(philo->time->ms_start), philo->num);
	pthread_mutex_unlock(philo->display);
}
void	r_eat(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	// pthread_mutex_lock(philo->m_eat);
	// usleep(philo->time->ms_to_eat);
	pthread_mutex_lock(philo->display);
	printf("%d	%d	is eating...\n", get_ms(philo->time->ms_start), philo->num);
	pthread_mutex_unlock(philo->display);
}
void	r_sleep(t_philo *philo)
{
	// pthread_mutex_unlock(philo->m_eat);
	pthread_mutex_lock(philo->display);
	printf("%d	%d	is sleeping...\n", get_ms(philo->time->ms_start), philo->num);
	pthread_mutex_unlock(philo->display);
}
void	r_think(t_philo *philo)
{
	philo->time->count = 1;
	pthread_mutex_lock(philo->display);
	printf("%d	%d	is thinking...\n", get_ms(philo->time->ms_start), philo->num);
	pthread_mutex_unlock(philo->display);
}
