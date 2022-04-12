/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:35:41 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/12 22:37:06 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data)
{
	free(data->philos);
	free(data->forks);
}

void	destroy_all(t_data *data)
{
	int	i;

	if (pthread_mutex_destroy(&data->display) != 0)
		exit_error_free("mutex destroy", data);
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_destroy(&data->forks[i++]) != 0)
			exit_error_free("mutex destroy", data);
	}
}

int	exit_error(const char *msg)
{
	printf("error: %s\n", msg);
	exit(1);
}

int	exit_error_free(const char *msg, t_data *data)
{
	free_all(data);
	printf("error: %s\n", msg);
	exit(1);
}
