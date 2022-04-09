/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:39:19 by kychoi            #+#    #+#             */
/*   Updated: 2022/04/09 22:05:15 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_ms(int ms)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec - ms);
}

void	take_fork(t_philo *philo, int nth)
{
	pthread_mutex_lock(&philo->display);
	pthread_mutex_lock(&philo->forks[philo->persons[nth].fork1]);
	printf("%d %d takes a fork.(fork1:%d, fork2:%d) \n", get_ms(philo->ms), nth + 1, philo->persons[nth].fork1, philo->persons[nth].fork2);
	pthread_mutex_lock(&philo->forks[philo->persons[nth].fork2]);
	printf("%d %d takes a fork.(fork1:%d, fork2:%d) \n", get_ms(philo->ms), nth + 1, philo->persons[nth].fork1, philo->persons[nth].fork2);
	pthread_mutex_unlock(&philo->display);
}

void	eating(t_philo *philo, int nth)
{
	printf("%d %d has is eating.(i:%d) \n", get_ms(philo->ms), philo->i + 1, philo->i);
	pthread_mutex_unlock(&philo->forks[philo->persons[nth].fork1]);
	pthread_mutex_unlock(&philo->forks[philo->persons[nth].fork2]);
}
void	sleeping(t_philo *philo)
{
	printf("%d %d has is sleeping.(i:%d)\n", get_ms(philo->ms), philo->i + 1, philo->i);
}

void	thinking(t_philo *philo)
{
}