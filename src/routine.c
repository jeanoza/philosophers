/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:59:20 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/18 17:17:09 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int		is_die(t_philo *philo)
{
	int	ms_current;

	ms_current = (int) get_micro_sec(philo->time->micro_start) / 1000;
	printf("is_die)		[ms_current]%d [philo->ms_to_die]%d\n", ms_current,philo->ms_to_die);
		// printf("%d	%d	has been died\n", ms_current, philo->num);
	if (ms_current >= philo->ms_to_die)
	{
		printf("%d	%d	has been died\n", ms_current, philo->num);
		// destroy_all(philo->data);
		// free_all(philo->data);
		system("leaks philo");
		exit (1);
	}
	return (0);
}
void	routine(void *param)
{
	t_philo	*philo;
	
	philo = param;
	//FIXME:this trigger have to remove | change with time
	while (philo->count_to_eat > 0)
	{
		if (!is_die(philo))
			r_take_fork(philo);
		if (!is_die(philo))
			r_eat(philo);
		if (!is_die(philo))
			r_sleep(philo);
		if (!is_die(philo))
			r_think(philo);
	}
}