/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:57:10 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/20 21:52:09 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_forks(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i++], NULL) != 0)
			return (1);
	}
	i = -1;
	while (++i < data->nb_philos)
	{
		philo = &data->philos[i];
		philo->fork1 = &data->forks[i];
		philo->fork2 = &data->forks[(i + 1) % data->nb_philos];
	}
	return (0);
}

static int	init_threads(t_data *data, t_time *time)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		data->philos[i].num = i + 1;
		data->philos[i].count_to_eat = time->count;
		data->philos[i].ms_to_die = time->ms_to_die;
		data->philos[i].m_display = &data->m_display;
		data->philos[i].time = time;
		data->philos[i].data = data;
		if (pthread_create(&data->philos[i].thread, NULL,
				(void *)&routine, (void *) &data->philos[i]) != 0)
			return (1);
		++i;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_join(data->philos[i++].thread, NULL) != 0)
			return (1);
	}
	return (0);
}

int	init(t_data *data, t_time *time)
{
	time->micro_start = get_micro_sec(0);
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (data->forks == NULL || data->forks == NULL)
		return (print_error_u("malloc error"));
	if (init_forks(data) != 0
		&& pthread_mutex_init(&data->m_display, NULL) != 0)
		return (print_error_u("mutex init"));
	if (init_threads(data, time) != 0)
		return (print_error_u("thread create/join"));
	return (0);
}
