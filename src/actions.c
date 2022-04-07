/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:39:19 by kychoi            #+#    #+#             */
/*   Updated: 2022/04/07 13:09:22 by kychoi           ###   ########.fr       */
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
	printf("%d %d has taken a fork(i:%d).\n", get_ms(philo->ms), philo->i + 1, philo->i);
}

void	eating(t_philo *philo)
{
	philo->persons[philo->i] = 2;
	printf("%d %d has is eating.(i:%d)\n", get_ms(philo->ms), philo->i + 1, philo->i);
}
void	sleeping(t_philo *philo)
{
	philo->persons[philo->i] = 3;
	philo->forks[philo->i] = 1;
	philo->forks[philo->i + 1] = 1;
	printf("%d %d has is sleeping.(i:%d)\n", get_ms(philo->ms), philo->i + 1, philo->i);
}

void	thinking(t_philo *philo)
{
}