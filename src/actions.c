/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:39:19 by kychoi            #+#    #+#             */
/*   Updated: 2022/04/09 16:31:47 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_ms(int ms)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec - ms);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->display);
	pthread_mutex_lock(&philo->forks[philo->i]);
	printf("%d %d has taken a fork(i:%d) .\n", get_ms(philo->ms), philo->i + 1, philo->i);
	pthread_mutex_unlock(&philo->display);
	pthread_mutex_lock(&philo->display);
	pthread_mutex_lock(&philo->forks[philo->i + 1]);
	printf("%d %d has taken a fork(i:%d) .\n", get_ms(philo->ms), philo->i + 1, philo->i);
	pthread_mutex_unlock(&philo->display);
}

void	eating(t_philo *philo)
{
	printf("%d %d has is eating.(i:%d) \n", get_ms(philo->ms), philo->i + 1, philo->i);
	pthread_mutex_unlock(&philo->forks[philo->i]);
	pthread_mutex_unlock(&philo->forks[philo->i + 1]);
}
void	sleeping(t_philo *philo)
{
	printf("%d %d has is sleeping.(i:%d)\n", get_ms(philo->ms), philo->i + 1, philo->i);
}

void	thinking(t_philo *philo)
{
}