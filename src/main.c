/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:26:18 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/14 11:41:14 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse(t_data *data, t_time *time, char **av)
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

int	main(int ac, char **av)
{
	t_data	data;
	t_time	time;

	if (ac < 5 || ac > 6)
		exit_error("arguments not enough or too much\n");
	parse(&data, &time, av);
	init(&data, &time, av);
	destroy_all(&data);
	free_all(&data);
	return (0);
}