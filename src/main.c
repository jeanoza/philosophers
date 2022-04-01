/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:26:18 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/04/01 09:34:33 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	parsing(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
		return (0);
	i = 0;
	while (av && av[i])
	{
		//TODO: add args condition au fur et a mesure
		++i;
	}
	return (1);
}

// int	main(int ac, char **av)
// {
// 	int			philo_num;

// 	(void)ac;
// 	(void)av;

// 	// if (!parsing(ac, av))
// 	// 	return (0);
// 	// philo_num = ft_atoi(av[1]);


// 	return (0);
// }

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
	test.mutex = (pthread_mutex_t) PTHREAD_MUTEX_INITIALIZER;


    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, func3, &test);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("%d\n", test.value);
    exit(EXIT_SUCCESS);
}