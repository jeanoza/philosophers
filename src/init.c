/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:57:10 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/12 08:58:17 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_data *data)
{
	int	i;
	t_philo	*philo;

	i = 0;
	while (i < data->nb_philos)
		pthread_mutex_init(&data->forks[i++], NULL);
	i = 0;
	while (i < data->nb_philos)
	{
		philo = &data->philos[i];
		philo->fork1 = &data->forks[i];
		philo->fork2 = &data->forks[++i % data->nb_philos];
	}
}

void	init(t_data *data, char **av)
{
	int	i;

	data->nb_philos = ft_atoi(av[1]);
	data->ms_start = get_ms(0);
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	init_forks(data);
	pthread_mutex_init(&data->display, NULL);
	i = 0;
	while (i < data->nb_philos)
	{
		data->philos[i].num = i + 1;
		data->philos[i].ms_start = data->ms_start;
		data->philos[i].display = &data->display;
		pthread_create(&data->philos[i].thread, NULL, (void *)&routine, (void *) &data->philos[i]);
		++i;
	}
	i = 0;
	while (i < data->nb_philos)
		pthread_join(data->philos[i++].thread, NULL);
}
