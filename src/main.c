/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:26:18 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/02 11:41:18 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int ac, char **av, t_philo *philo)
{
	int	i;

	if (ac < 5 || ac > 6)
		return (0);
	i = 0;
	while (av && av[++i])
	{
		if (i == 1)
		{
			philo->nb_forks = ft_atoi(av[i]);
			philo->nb_philos = ft_atoi(av[i]);
		}
		else if (i == 2)
			philo->ms_die = ft_atoi(av[i]);
		else if (i == 3)
			philo->ms_eat = ft_atoi(av[i]);
		else if (i == 4)
			philo->ms_sleep = ft_atoi(av[i]);
		else if (i == 5)
			philo->nb_must_eat = ft_atoi(av[i]);
	}
	return (1);
}

/*
 * av[1] = number_of_philosopers
 * av[2] = time_to_die
 * av[3] = time_to_eat
 * av[3] = time_to_sleep
 * av[5] = number_of_times_each_philosopher_must_eat
 */
int	main(int ac, char **av)
{
	t_philo	philo;



	memset(&philo, 0, sizeof(philo));
	if (!parsing(ac, av, &philo))
		return (0);
	printf("nb_forks:%d\n", philo.nb_forks);
	printf("nb_philos%d\n", philo.nb_philos);


	return (0);
}
