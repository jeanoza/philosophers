/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:57:10 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/12 22:38:51 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i++], NULL) != 0)
			exit_error("mutex init");
	}
	i = 0;
	while (i < data->nb_philos)
	{
		philo = &data->philos[i];
		philo->fork1 = &data->forks[i];
		philo->fork2 = &data->forks[++i % data->nb_philos];
	}
}

void	init_threads(t_data *data, t_time *time)
{
	int	i;

	if (pthread_mutex_init(&data->display, NULL) != 0)
		exit_error_free("mutex init", data);
	i = 0;
	while (i < data->nb_philos)
	{
		data->philos[i].num = i + 1;
		data->philos[i].display = &data->display;
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
	time->ms_start = get_ms(0);
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (data->philos == NULL)
		exit_error("malloc error");
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (data->forks == NULL)
	{
		free(data->philos);
		exit_error("malloc error");
	}
	init_forks(data);
	init_threads(data, time);
}
