/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:26:18 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/11 08:35:55 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_data *data)
{


}
void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	pthread_mutex_lock(philo->fork2);
	pthread_mutex_lock(philo->display);
	printf("%d	%d	takes a fork...\n", get_ms(philo->ms_start), philo->num);
	printf("%d	%d	takes a fork...\n", get_ms(philo->ms_start), philo->num);
	pthread_mutex_unlock(philo->display);
}
void	eating(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	pthread_mutex_lock(philo->display);
	//FIXME:this trigger have to remove | change with time
	philo->count = 1;
	printf("%d	%d	is eating...\n", get_ms(philo->ms_start), philo->num);
	pthread_mutex_unlock(philo->display);
}
void	routine(void *param)
{
	t_philo	*philo;

	philo = param;

	//FIXME:this trigger have to remove | change with time
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
	data.ms_start = get_ms(0);
	data.philos = malloc(sizeof(t_philo) * data.nb_philos);
	data.forks = malloc(sizeof(pthread_mutex_t) * data.nb_philos);
	init_forks(&data);
	pthread_mutex_init(&data.display, NULL);
	i = 0;
	while (i < nb_philos)
	{
		data.philos[i].num = i + 1;
		data.philos[i].ms_start = data.ms_start;
		data.philos[i].display = &data.display;
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