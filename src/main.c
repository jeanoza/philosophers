/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:26:18 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/02 17:31:14 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_philo *philo)
{
	int	i;

	philo->person = malloc(sizeof(t_person) * philo->nb_philos);
	if (!philo->person)
		return ;
	i = -1;
	while (++i < philo->nb_philos)
		(philo->person + i)->status = 0;
}


//Mutex examples...
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#ifndef NUM_THREADS
#define NUM_THREADS 4
#endif


typedef struct s_test {
   pthread_mutex_t mutex;
   int				value;
}	t_test;

void *func3(void* param)
{
   pthread_mutex_lock(&(((t_test*)param)->mutex));
   printf("Incrementing the shared variable...\n");
   for (int i = 0; i < 10000; ++i) {
      ((t_test*)param)->value += 1;
   }
   pthread_mutex_unlock(&(((t_test*)param)->mutex));
   return 0;
}

int main()
{
   pthread_t threads[NUM_THREADS];
   t_test	test;
   test.value = 0;
//    test.mutex = (pthread_mutex_t) PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_init(&test.mutex, NULL);


   for (int i = 0; i < NUM_THREADS; ++i) {
      pthread_create(&threads[i], NULL, func3, &test);
   }

   for (int i = 0; i < NUM_THREADS; ++i) {
      pthread_join(threads[i], NULL);
   }

   printf("%d\n", test.value);
   exit(EXIT_SUCCESS);
}
/*
 * av[1] = number_of_philosopers
 * av[2] = time_to_die
 * av[3] = time_to_eat
 * av[3] = time_to_sleep
 * av[5] = number_of_times_each_philosopher_must_eat
 */
// int	main(int ac, char **av)
// {
// 	t_philo	philo;

// 	memset(&philo, 0, sizeof(philo));
// 	if (!parsing(ac, av, &philo))
// 		return (0);
// 	init(&philo);

// 	return (0);
// }

// // FIXME: verify parsing result.
// printf("nb_forks: %d\n", philo.nb_forks);
// printf("nb_philos: %d\n", philo.nb_philos);
// printf("ms_die: %d\n", philo.ms_die);
// printf("ms_eat: %d\n", philo.ms_eat);

// // FIXME:test init
// int i = -1;
// while (++i < philo.nb_philos)
// 	printf("person[%p] status:%d\n", philo.person + i, (philo.person + i)->status);
