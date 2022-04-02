/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:11:33 by kychoi            #+#    #+#             */
/*   Updated: 2022/04/02 19:04:59 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	put_val(t_philo *philo, int i, int current)
{
	if (i == 1)
		philo->nb_philos = current;
	else if (i == 2)
		philo->ms_die = current;
	else if (i == 3)
		philo->ms_eat = current;
	else if (i == 4)
		philo->ms_sleep = current;
	else if (i == 5)
		philo->nb_must_eat = current;
}

int	parsing(int ac, char **av, t_philo *philo)
{
	int	i;
	int	current;

	if (ac < 5 || ac > 6)
		return (0);
	if (ft_atoi(av[1]) == 1)
	{
		printf("[Warnning] At least need two philosophers!\n");
		return (0);
	}
	i = 0;
	while (av && av[++i])
	{
		current = ft_atoi(av[i]);
		if (current < 1)
			return (0);
		put_val(philo, i, current);
	}
	return (1);
}
