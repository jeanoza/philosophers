/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:57:10 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/18 13:18:26 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_data *data, pthread_mutex_t *mutexes, int opt, int i)
{
	t_philo	*philo;

	if (mutexes == NULL)
		exit_error_free("malloc error", data);
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&mutexes[i++], NULL) != 0)
			exit_error("mutex init");
	}
	i = -1;
	while (++i < data->nb_philos)
	{
		philo = &data->philos[i];
		if (opt == M_FORKS)
		{
			philo->fork1 = &mutexes[i];
			philo->fork2 = &mutexes[(i + 1) % data->nb_philos];
		}
		// else if (opt == M_EAT)
		// 	philo->m_eat = &mutexes[i];
		// else if (opt == M_SLEEP)
		// 	philo->m_sleep = &mutexes[i];
		// else if (opt == M_THINK)
		// 	philo->m_think = &mutexes[i];
	}
}

void	init_threads(t_data *data, t_time *time)
{
	int	i;

	if (pthread_mutex_init(&data->m_display, NULL) != 0)
		exit_error_free("mutex init", data);
	i = 0;
	while (i < data->nb_philos)
	{
		data->philos[i].num = i + 1;
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
	// data->m_eat = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	// data->m_sleep = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	// data->m_think = malloc(sizeof(pthread_mutex_t) * data->nb_philos);

	init_mutex(data, data->forks, M_FORKS, 0);
	// init_mutex(data, data->m_eat, M_EAT, 0);
	// init_mutex(data, data->m_sleep, M_SLEEP, 0);
	// init_mutex(data, data->m_think, M_THINK, 0);
	init_threads(data, time);
}
