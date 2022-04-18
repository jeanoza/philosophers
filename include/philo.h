/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:05:07 by kychoi            #+#    #+#             */
/*   Updated: 2022/04/18 14:57:48 by kyubongchoi      ###   ########.fr       */
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
	long long	micro_start;
	int	ms_to_die;
	int	ms_to_eat;
	int	ms_to_sleep;
	int	count;
}	t_time;

typedef struct s_philo {
	int				num;
	int				count_to_eat;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
	// pthread_mutex_t	*m_eat;
	// pthread_mutex_t	*m_sleep;
	// pthread_mutex_t	*m_think;
	pthread_mutex_t	*m_display;
	pthread_t		thread;
	t_time			*time;
}	t_philo;

typedef struct s_data {
	int				nb_philos;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	// pthread_mutex_t	*m_eat;
	// pthread_mutex_t	*m_sleep;
	// pthread_mutex_t	*m_think;
	pthread_mutex_t	m_display;
}	t_data;

# define M_FORKS 0
# define M_EAT 1
# define M_SLEEP 2
# define M_THINK 3
# define M_DISPLAY 4

# define MSG_FORKS "has taken a fork"
# define MSG_EAT "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_THINK "is thinking"


/* utils */
int		ft_strlen(char *str);
int		ft_atoi(char *str);
long long	get_micro_sec(long long micro_start);

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
