/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:26:18 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/02 13:07:56 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_val(t_philo *philo, int i, int current)
{
	if (i == 1)
	{
		philo->nb_forks = current;
		philo->nb_philos = current;
	}
	else if (i == 2)
		philo->ms_die = current;
	else if (i == 3)
		philo->ms_eat = current;
	else if (i == 4)
		philo->ms_sleep = current;
	else if (i == 5)
		philo->nb_must_eat = current;
}

int	parsing(int ac, char **av, t_philo *philo)
{
	int	i;
	int	current;

	if (ac < 5 || ac > 6)
		return (0);
	if (ft_atoi(av[1]) == 1)
	{
		printf("[Warnning] At least need two philosophers!\n");
		return (0);
	}
	i = 0;
	while (av && av[++i])
	{
		current = ft_atoi(av[i]);
		if (current < 1)
			return (0);
		put_val(philo, i, current);
	}
	return (1);
}


// //Mutex examples...
// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <unistd.h>

// #ifndef NUM_THREADS
// #define NUM_THREADS 4
// #endif


// typedef struct s_test {
//    pthread_mutex_t mutex;
//    int				value;
// }	t_test;

// void *func3(void* param)
// {
//    pthread_mutex_lock(&(((t_test*)param)->mutex));
//    printf("Incrementing the shared variable...\n");
//    for (int i = 0; i < 10000; ++i) {
//       ((t_test*)param)->value += 1;
//    }
//    pthread_mutex_unlock(&(((t_test*)param)->mutex));
//    return 0;
// }

// int main()
// {
//    pthread_t threads[NUM_THREADS];
//    t_test	test;
//    test.value = 0;
// //    test.mutex = (pthread_mutex_t) PTHREAD_MUTEX_INITIALIZER;
// 	pthread_mutex_init(&test.mutex, NULL);


//    for (int i = 0; i < NUM_THREADS; ++i) {
//       pthread_create(&threads[i], NULL, func3, &test);
//    }

//    for (int i = 0; i < NUM_THREADS; ++i) {
//       pthread_join(threads[i], NULL);
//    }

//    printf("%d\n", test.value);
//    exit(EXIT_SUCCESS);
// }
/*
 * av[1] = number_of_philosopers
 * av[2] = time_to_die
 * av[3] = time_to_eat
 * av[3] = time_to_sleep
 * av[5] = number_of_times_each_philosopher_must_eat
 */
int	main(int ac, char **av)
{
	t_philo	philo;

	memset(&philo, 0, sizeof(philo));
	if (!parsing(ac, av, &philo))
		return (0);
	printf("nb_forks: %d\n", philo.nb_forks);
	printf("nb_philos: %d\n", philo.nb_philos);
	printf("ms_die: %d\n", philo.ms_die);
	printf("ms_eat: %d\n", philo.ms_eat);
	return (0);
}
