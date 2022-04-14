/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:57:10 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/14 12:22:22 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_data *data)
{
	int		i;
	t_philo	*philo;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (data->forks == NULL)
		exit_error_free("malloc error", data);
	i = -1;
	while (++i < data->nb_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
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

/*
 * opt
 * forks = 0
 * m_eat = 1
 * m_sleep = 2
 * m_think = 3
 */
void	init_mutex_generic(t_data *data, pthread_mutex_t *mutexes, char opt)
{
	int		i;
	t_philo	*philo;

	mutexes = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (mutexes == NULL)
		exit_error_free("malloc error", data);
	i = -1;
	while (++i < data->nb_philos)
	{
		if (pthread_mutex_init(&mutexes[i], NULL) != 0)
			exit_error("mutex init");
	}
	i = -1;
	while (++i < data->nb_philos)
	{
		philo = &data->philos[i];
		if (opt == 0)
		{
			philo->fork1 = &mutexes[i];
			philo->fork2 = &mutexes[(i + 1) % data->nb_philos];
		}
		if (opt == 1)
			philo->m_eat = &mutexes[i];
		if (opt == 2)
			philo->m_sleep = &mutexes[i];
		if (opt == 3)
			philo->m_think = &mutexes[i];
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
	//TODO: each data, who i malloacte, must initialize with NULL or not?
	data->philos = NULL;
	data->forks = NULL;
	data->m_eat = NULL;
	data->m_sleep = NULL;
	data->m_think = NULL;
	time->ms_start = get_ms(0);
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (data->philos == NULL)
		exit_error("malloc error");
	init_forks(data);
	// init_mutex_generic(data, data->forks, 0);
	init_mutex_generic(data, data->m_eat, M_EAT);
	init_mutex_generic(data, data->m_sleep, M_SLEEP);
	init_mutex_generic(data, data->m_think, M_THINK);
	int i = -1;
	while (++i < data->nb_philos)
	{
		printf("philo[%d]->m_fork1\t[%p]\n",i, data->philos[i].fork1);
		printf("philo[%d]->m_fork2\t[%p]\n",i, data->philos[i].fork2);
		printf("philo[%d]->m_eat\t[%p]\n",i, data->philos[i].m_eat);
		printf("philo[%d]->m_sleep\t[%p]\n",i, data->philos[i].m_sleep);
		printf("philo[%d]->m_think\t[%p]\n\n",i, data->philos[i].m_think);

	}
	init_threads(data, time);
}
