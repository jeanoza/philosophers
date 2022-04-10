/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:26:18 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/11 00:18:49 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_data *data)
{


}
void	take_fork(t_philo *philo)
{
	// printf("num:%d fork1[%p] fork2[%p]\n", philo->num, philo->fork1, philo->fork2);
	pthread_mutex_lock(philo->fork1);
	printf("%d takes a fork\n", philo->num);
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_lock(philo->fork2);
	printf("%d takes a fork\n", philo->num);
	pthread_mutex_unlock(philo->fork2);
}
void	eating(t_philo *philo)
{
	philo->count = 1;
	printf("%d is eating\n", philo->num);
}
void	routine(void *param)
{
	t_philo	*philo;

	philo = param;

	while (philo->count != 1)
	{
		take_fork(philo);
		eating(philo);
	}
}

void	init_forks(t_data *data)
{
	int	i;
	t_philo	*philo;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		++i;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		philo = &data->philos[i];
		philo->fork1 = &data->forks[i];
		philo->fork2 = &data->forks[(i + 1) % data->nb_philos];
		++i;
	}
}
int	main(int ac, char **av)
{
	int	nb_philos = 10;
	int	i;
	t_data	data;

	data.nb_philos = nb_philos;
	data.philos = malloc(sizeof(t_philo) * data.nb_philos);
	data.forks = malloc(sizeof(pthread_mutex_t) * data.nb_philos);
	init_forks(&data);
	i = 0;
	while (i < nb_philos)
	{
		data.philos[i].num = i + 1;
		pthread_create(&data.philos[i].thread, NULL, (void *)&routine, (void *) &data.philos[i]);
		++i;
	}
	i = 0;
	while (i < nb_philos)
	{
		pthread_join(data.philos[i].thread, NULL);
		++i;
	}

	return (0);
}