/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:26:18 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/24 17:50:28 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	one_philo(int ms_to_die)
{
	long long	current_time;

	current_time = get_time();
	printf("0	1	has taken a fork\n");
	usleep(ms_to_die * 1000);
	return (printf("%d	1	died\n", ms_to_die));
}

static int	parse(t_data *data, t_time *time, char **av)
{
	int	i;

	memset(data, 0, sizeof(t_data));
	memset(time, 0, sizeof(t_time));
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

static int	all_ate(t_data *data, t_time *time)
{
	int	i;

	i = 0;
	if (time->count_to_eat == 0)
		return (0);
	while (i < data->nb_philos)
	{
		if (data->philos[i].eat_count != time->count_to_eat)
			return (0);
		++i;
	}
	return (1);
}
// static int	find_dead_person(t_data *data, t_time *time)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->nb_philos)
// 	{
// 		if (data->philos[i].eat_count != time->count_to_eat)
// 			return (0);
// 		++i;
// 	}
// }

int	main(int ac, char **av)
{
	t_data	data;
	t_time	time;
	int		i;

	if (ac < 5 || ac > 6)
		return (print_error_u("arguments not enough or too much\n"));
	if (parse(&data, &time, av) == 0 && init(&data, &time) == 0)
	{
		i = 0;
		while (!data.first_dead)
		{
			pthread_mutex_lock(&data.m_life);
			data.ms_current = get_time() - time.ms_start;
			if (data.ms_current > data.philos[i].ms_to_die)
			{
				data.first_dead = data.philos[i].num;
				pthread_mutex_unlock(&data.m_life);
				break;
			}
			i = (i + 1) % data.nb_philos;
			pthread_mutex_unlock(&data.m_life);
		}
	}
	if (all_ate(&data, &time))
		printf("All philosophers have eaten!\n");
	else
		printf("%lld	%d	is dead\n", data.ms_current, data.first_dead);
	destroy_all(&data);
	free_all(&data);
	return (0);
}