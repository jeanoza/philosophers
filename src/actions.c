/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:36:34 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/12 20:47:08 by kyubongchoi      ###   ########.fr       */
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
	pthread_mutex_lock(philo->display);
	//FIXME:this trigger have to remove | change with time
	printf("%d	%d	is eating...\n", get_ms(philo->time->ms_start), philo->num);
	pthread_mutex_unlock(philo->display);
	usleep(2 * 1000);
}
void	r_sleep(t_philo *philo)
{
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
