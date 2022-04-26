/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:57:10 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/23 21:58:42 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex(t_data *data)
{
	t_philo	*philo;
	int		i;

	if (pthread_mutex_init(&data->m_display, NULL) != M_SUCCESS
		|| pthread_mutex_init(&data->m_life, NULL) != M_SUCCESS)
		return (1);
	i = -1;
	while (++i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->m_forks[i], NULL) != M_SUCCESS)
			return (1);
	}
	i = -1;
	while (++i < data->nb_philos)
	{
		philo = &data->philos[i];
		philo->m_fork1 = &data->m_forks[i];
		philo->m_fork2 = &data->m_forks[(i + 1) % data->nb_philos];
	}
	return (M_SUCCESS);
}

static int	init_threads(t_data *data, t_time *time)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		data->philos[i].num = i + 1;
		data->philos[i].eat_count = 0;
		data->philos[i].ms_to_die = time->ms_to_die;
		data->philos[i].m_display = &data->m_display;
		data->philos[i].m_life = &data->m_life;
		data->philos[i].time = time;
		data->philos[i].data = data;
		if (pthread_create(&data->philos[i].thread, NULL,
				(void *)&routine, (void *) &data->philos[i]) != M_SUCCESS)
			return (1);
		++i;
	}
	i = 0;
	// while (i < data->nb_philos)
	// 	pthread_join(data->philos[i++].thread, NULL);
	return (M_SUCCESS);
}

int	init(t_data *data, t_time *time)
{
	time->ms_start = get_time();
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	data->m_forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (data->philos == NULL || data->m_forks == NULL)
		return (print_error_i("malloc error"));
	memset(data->philos, 0, sizeof(t_philo) * data->nb_philos);
	if (init_mutex(data) != M_SUCCESS)
		return (print_error_i("mutex init"));
	if (init_threads(data, time) != M_SUCCESS)
		return (print_error_i("thread create/join"));
	return (M_SUCCESS);
}
