/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:05:07 by kychoi            #+#    #+#             */
/*   Updated: 2022/04/12 22:37:24 by kyubongchoi      ###   ########.fr       */
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

typedef struct s_time {
	int	ms_start;
	int	ms_to_die;
	int	ms_to_eat;
	int	ms_to_sleep;
	int	count;
}	t_time;

typedef struct s_philo {
	int				num;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
	pthread_mutex_t	*display;
	pthread_t		thread;
	t_time			*time;
}	t_philo;

/*
 * forks[i]: 0 => non-available, 1 => available
 * persons[i]: 0 => default, 1 => after eat, 2 => after sleep, 3 => after think
 */
typedef struct s_data {
	int				nb_philos;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	display;
}	t_data;

/* utils */
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		get_ms(int ms);

/* actions.c */
void	r_take_fork(t_philo *philo);
void	r_eat(t_philo *philo);
void	r_sleep(t_philo *philo);
void	r_think(t_philo *philo);

/* routine.c */
void	routine(void *param);

/* init.c */
void	init(t_data *data, t_time *time, char **av);

/* exit.c */
void	free_all(t_data *data);
void	destroy_all(t_data *data);
int		exit_error(const char *msg);
int		exit_error_free(const char *msg, t_data *data);

#endif
