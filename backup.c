typedef struct s_philo {
	int				num;
	int				count_to_eat;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*m_fork2;
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
	pthread_mutex_t	*m_forks;
	// pthread_mutex_t	*m_eat;
	// pthread_mutex_t	*m_sleep;
	// pthread_mutex_t	*m_think;
	pthread_mutex_t	m_display;
}	t_data;

// FIXME: if must init each mutex for protection... use this function.
void	init_mutex(t_data *data, pthread_mutex_t *mutexes, int opt, int i)
{
	t_philo	*philo;

	if (mutexes == NULL)
		print_error_u_free("malloc error", data);
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&mutexes[i++], NULL) != 0)
			print_error_u("mutex init");
	}
	i = -1;
	while (++i < data->nb_philos)
	{
		philo = &data->philos[i];
		if (opt == M_FORKS)
		{
			philo->fork1 = &mutexes[i];
			philo->m_fork2 = &mutexes[(i + 1) % data->nb_philos];
		}
		// else if (opt == M_EAT)
		// 	philo->m_eat = &mutexes[i];
		// else if (opt == M_SLEEP)
		// 	philo->m_sleep = &mutexes[i];
		// else if (opt == M_THINK)
		// 	philo->m_think = &mutexes[i];
	}
}

void	init(t_data *data, t_time *time, char **av)
{
	time->ms_start = get_time(0);
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	data->m_forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	// data->m_eat = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	// data->m_sleep = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	// data->m_think = malloc(sizeof(pthread_mutex_t) * data->nb_philos);

	// init_mutex(data, data->m_forks, M_FORKS, 0);
	// init_mutex(data, data->m_eat, M_EAT, 0);
	// init_mutex(data, data->m_sleep, M_SLEEP, 0);
	// init_mutex(data, data->m_think, M_THINK, 0);
	init_threads(data, time);
}

void	free_all(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->m_forks)
		free(data->m_forks);
	// if (data->m_sleep)
	// 	free(data->m_sleep);
	// if (data->m_eat)
	// 	free(data->m_eat);
	// if (data->m_think)
	// 	free(data->m_think);
}

void	destroy_all(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->m_display);
	i = -1;
	while (++i < data->nb_philos)
	{
		if (&data->m_forks[i])
			pthread_mutex_destroy(&data->m_forks[i]);
		// if (&data->m_eat[i])
		// 	pthread_mutex_destroy(&data->m_eat[i]);
		// if (&data->m_sleep[i])
		// 	pthread_mutex_destroy(&data->m_sleep[i]);
		// if (&data->m_think[i])
		// 	pthread_mutex_destroy(&data->m_think[i]);
	}
}