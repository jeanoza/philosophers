/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:11:02 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/05/01 23:08:50 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		++i;
	return (i);
}

int	ft_strcmp(char const *s1, char const *s2)
{
	int	i;

	if (s1 == s2)
		return (0);
	i = 0;
	while (s1 && s2 && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

void	sleep_ajusted(long long ms)
{
	long long	current;

	current = get_time();
	while ((get_time() - current) < ms)
		usleep(128);
}

int	ft_atoi(char *str)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	while (str && str[i] && str[i] >= '0' && str[i] <= '9' )
		res = (10 * res) + (str[i++] - '0');
	res = (sign * res);
	if (res > INT_MAX || res < INT_MIN)
		return (-42);
	return ((int) res);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
