/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:35:41 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/18 15:28:53 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
}

void	destroy_all(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->m_display);
	i = -1;
	while (++i < data->nb_philos)
	{
		if (&data->forks[i])
			pthread_mutex_destroy(&data->forks[i]);
	}
}
int	exit_error(const char *msg)
{
	printf("error: %s\n", msg);
	exit(1);
}

int	exit_error_free(const char *msg, t_data *data)
{
	destroy_all(data);
	free_all(data);
	printf("error: %s\n", msg);
	exit(1);
}
