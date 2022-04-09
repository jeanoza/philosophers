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

static void	case_odd(t_philo *philo, int nth)
{
	while (1)
	{
		take_fork(philo, nth);
		eating(philo, nth);
		return;
	}
}
static void	case_even(t_philo *philo, int nth)
{
	// while (1)
	// {
	// 	take_fork(philo, nth);
	// 	eating(philo);
	// 	return ;
	// }
}

void	*algo(void *param)
{
	case_odd((t_philo *) param, ((t_philo *) param)->i);
	return (0);
}
