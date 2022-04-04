/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:39:19 by kychoi            #+#    #+#             */
/*   Updated: 2022/04/04 20:22:09 by kyubongchoi      ###   ########.fr       */
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
	philo->forks[philo->i] = 0;
	philo->forks[philo->i + 1] = 0;
	philo->persons[philo->i] = 1;
	printf("%d %d has taken a fork.\n", get_ms(philo->ms), philo->i + 1);
}

void	eating(t_philo *philo)
{
	philo->persons[philo->i] = 2;
	printf("%d %d has is eating.\n", get_ms(philo->ms), philo->i + 1);
}
void	sleeping(t_philo *philo)
{
	philo->persons[philo->i] = 3;
	philo->forks[philo->i] = 1;
	philo->forks[philo->i + 1] = 1;
	printf("%d %d has is sleeping.\n", get_ms(philo->ms), philo->i + 1);
}

void	thinking(t_philo *philo)
{
}