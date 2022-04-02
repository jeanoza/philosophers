/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:05:07 by kychoi            #+#    #+#             */
/*   Updated: 2022/04/02 19:44:21 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

/*
 * forks[i]: 0 => non-available, 1 => available
 * persons[i]: 0 => default, 1 => after eat, 2 => after sleep, 3 => after think
 */
typedef struct s_philo {
	int				nb_philos;
	int				ms_die;
	int				ms_eat;
	int				ms_sleep;
	int				nb_must_eat;
	int				*forks;
	int				*persons;
	pthread_mutex_t	mutex;
}	t_philo;

int	ft_strlen(char *str);
int	ft_atoi(char *str);
int	parsing(int ac, char **av, t_philo *philo);

#endif
