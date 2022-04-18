/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:57:10 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/18 15:19:59 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_data *data)
{
	t_philo	*philo;
	int		i;

	if (data->forks == NULL)
		exit_error_free("malloc error", data);
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i++], NULL) != 0)
			exit_error("mutex init");
	}
	i = -1;
	while (++i < data->nb_philos)
	{
		philo = &data->philos[i];
		philo->fork1 = &data->forks[i];
		philo->fork2 = &data->forks[(i + 1) % data->nb_philos];
	}
}

void	init_threads(t_data *data, t_time *time)
{
	int	i;

	if (pthread_mutex_init(&data->m_display, NULL) != 0)
		exit_error_free("display mutex init", data);
	i = 0;
	while (i < data->nb_philos)
	{
		data->philos[i].num = i + 1;
		data->philos[i].count_to_eat = time->count;
		data->philos[i].m_display = &data->m_display;
		data->philos[i].time = time;
		if (pthread_create(&data->philos[i].thread, NULL,
				(void *)&routine, (void *) &data->philos[i]) != 0)
			exit_error_free("thread create", data);
		++i;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_join(data->philos[i++].thread, NULL) != 0)
			exit_error_free("thread join", data);
	}
}

void	init(t_data *data, t_time *time, char **av)
{
	time->micro_start = get_micro_sec(0);
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);

	init_forks(data);
	init_threads(data, time);
}
