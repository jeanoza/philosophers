/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:39:19 by kychoi            #+#    #+#             */
/*   Updated: 2022/04/02 22:19:04 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int		get_ms(t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec - philo->ms);

}
void	take_fork(t_philo *philo)
{
	printf("%d %d has taken a fork.\n", get_ms(philo), philo->i + 1);
	philo->forks[philo->i] = 0;
	philo->forks[philo->i + 1] = 0;
}

void	eating(t_philo *philo)
{

}
void	sleeping(t_philo *philo)
{
}

void	thinking(t_philo *philo)
{
}