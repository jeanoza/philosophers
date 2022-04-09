/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:34:39 by kychoi            #+#    #+#             */
/*   Updated: 2022/04/09 16:18:57y kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	case_odd(t_philo *philo)
{
	printf("case_odd(i:%d)\n", philo->i);
	while (1)
	{
		take_fork(philo);
		eating(philo);
		return ;
	}
}
static void	case_even(t_philo *philo)
{
	printf("case_even(i:%d)\n", philo->i);
	while (1)
	{
		take_fork(philo);
		eating(philo);
		return ;
	}
}

void	*algo(void *param)
{
	printf("algo:%d\n", ((t_philo *) param)->i);
	if (((t_philo *) param)->i % 2 == 0)
		case_odd(((t_philo *) param));
	else
		case_even(((t_philo *) param));
	return (0);
}
