/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:26:18 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/18 21:53:27 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	parse(t_data *data, t_time *time, char **av)
{
	int	i;

	if (av[5] && av[5][0] == '0')
		exit_error("[must_eat_time] cannot be '0' : you know:))");
	if (ft_atoi(av[1]) < 2)
		exit_error("only one philosopher cannot eat!");
	data->nb_philos = ft_atoi(av[1]);
	i = 2;
	while (av[i] && ft_atoi(av[i]))
	{
		if (i == 2)
			time->ms_to_die = ft_atoi(av[2]);
		else if (i == 3)
			time->ms_to_eat = ft_atoi(av[3]);
		else if (i == 4)
			time->ms_to_sleep = ft_atoi(av[4]);
		else if (i == 5)
			time->count = ft_atoi(av[5]);
		++i;
	}
	if (i < 5)
		exit_error("each args must be numeric more than 0!");
	if (i == 5)
		time->count = 1;
}

static int	is_everyone_eat(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		if (data->philos[i].count_to_eat != 0)
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_time	time;

	if (ac < 5 || ac > 6)
		exit_error("arguments not enough or too much\n");
	memset(&data, 0, sizeof(t_data));
	parse(&data, &time, av);
	init(&data, &time);
	if (is_everyone_eat(&data))
		printf("All philosophers have eaten!\n");
	destroy_all(&data);
	free_all(&data);
	// system("leaks philo");
	return (0);
}