/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:26:18 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/22 17:38:07 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	one_philo(int ms_to_die)
{
	long long	current_time;

	current_time = get_time();
	printf("0	1	has taken a fork\n");
	usleep(ms_to_die * 1000);
	// sleep_ajusted(ms_to_die);
	return (printf("%d	1	died\n", ms_to_die));
}

static int	parse(t_data *data, t_time *time, char **av)
{
	int	i;

	if (av[5] && av[5][0] == '0')
		return (print_error_u("[must_eat_time] cannot be '0' : you know:))"));
	i = 1;
	while (av[i] && ft_atoi(av[i]) > 0)
	{
		if (i == 2)
			time->ms_to_die = ft_atoi(av[2]);
		else if (i == 3)
			time->ms_to_eat = ft_atoi(av[3]);
		else if (i == 4)
			time->ms_to_sleep = ft_atoi(av[4]);
		else if (i == 5)
			time->count_to_eat = ft_atoi(av[5]);
		++i;
	}
	if (i < 5)
		return (print_error_u("each args must be numeric more than 0!"));
	if (ft_atoi(av[1]) == 1)
		return (one_philo(time->ms_to_die));
	data->nb_philos = ft_atoi(av[1]);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_time	time;

	if (ac < 5 || ac > 6)
		return (print_error_u("arguments not enough or too much\n"));
	memset(&data, 0, sizeof(t_data));
	if (parse(&data, &time, av) == 0 && init(&data, &time) == 0)
	{
		if (data.first_dead)
			printf("%lld	%d	died\n", data.ms_current, data.first_dead);
		else
			printf("All philosophers have eaten!\n");
	}
	destroy_all(&data);
	free_all(&data);
	return (0);
}