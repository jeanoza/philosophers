/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:35:41 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/05/01 22:15:57 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->m_forks)
		free(data->m_forks);
}

void	destroy_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		pthread_join(data->philos[i].thread, NULL);
	i = -1;
	while (++i < data->nb_philos)
	{
		if (data->m_forks && &data->m_forks[i])
			pthread_mutex_destroy(&data->m_forks[i]);
	}
	pthread_mutex_destroy(&data->m_life);
}

int	print_error_u(const char *msg)
{
	printf("%susage:	./philo <number_of_philosophers> ", COLOR_RED);
	printf("<time_to_die> <time_to_eat> <time_to_sleep> ");
	printf("[number_of_times_each_philosopher_must_eat]%s\n", COLOR_DEFAULT);
	return (printf("%serror: %s%s\n", COLOR_PURPLE, msg, COLOR_DEFAULT));
}

int	print_error_i(const char *msg)
{
	return (printf("%serror: %s%s\n", COLOR_PURPLE, msg, COLOR_DEFAULT));
}
