/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:34:39 by kychoi            #+#    #+#             */
/*   Updated: 2022/04/07 12:06:29 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	case_odd(t_philo *philo)
{
	// printf("case_odd(i:%d)\n", philo->i);
	while (philo->persons[philo->i] < 4)
	{
		if (philo->persons[philo->i] < 1
			&& (philo->forks[philo->i] == 1 && philo->forks[philo->i + 1] == 1))
			take_fork(philo);
		else if (philo->persons[philo->i] == 1)
			eating(philo);
		else if (philo->persons[philo->i] == 2)
			sleeping(philo);
		else return;
	}
}
static void	case_even(t_philo *philo)
{
	// printf("case_even(i:%d)\n", philo->i);
	if (philo->forks[philo->i] == 1 && philo->forks[philo->i + 1] == 1)
		take_fork(philo);
}

void	*algo(void *param)
{
	if (((t_philo *) param)->i % 2 == 0)
		case_odd(((t_philo *) param));
	else
		case_even(((t_philo *) param));
   	pthread_mutex_lock(&(((t_philo*)param)->mutex));
	((t_philo *) param)->i += 1;
   	pthread_mutex_unlock(&(((t_philo*)param)->mutex));
	return (0);
}
