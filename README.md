# Philosophers

## Resume

### Goal : imitate exactly `pipe` of terminal.

### Library && Function autorized

```c
/* unistd.h */
ssize_t write(int fildes, const void *buf, size_t nbyte);
int		usleep(useconds_t microseconds);

/* stdlib.h */
int		malloc(size_t size);
void    free(void *ptr);

/* stdio.h */
int		printf(const char *restrict format, ...);

/* string.h */
void	*memset(void *b, int c, size_t len);

/* sys/time.h */
int		gettimeofday(struct timeval *restrict tp, void *restrict tzp);

/* pthread.h */
int		pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
int		pthread_datach(pthread_t thread);
int		pthread_join(pthread_t thread, void **value_ptr);
int		pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
int		pthread_mutex_destroy(pthread_mutex_t *mutex);
int		pthread_mutex_lock(pthread_mutex_t *mutex);
int		pthread_mutex_unlock(pthread_mutex_t *mutex);

```

### Subject

1. Only one action : eat | sleep | think

   > - Les philosophes sont soit en train de manger, de penser ou de dormir.
   >
   > - Lorsqu’ils mangent, ils ne peuvent pas penser ou dormir.
   >
   > - Lorsqu’ils dorment, ils ne peuvent pas manger ou penser.
   >
   > - Enfin, lorsqu’ils pensent, ils ne peuvent pas manger ou dormir

2. Fork quantity == Philosophers number

   > - Il y a également des fourchettes sur la table.
   >
   > - Il y a <strong>autant de fourchettes que de philosophes</strong>

3. Need TWO FORK to eat

   > - Puisque servir et manger des spaghetti à l’aide d’une seule fourchette n’est pas chose facile
   >
   > - un philosophe prend la fourchette sur sa gauche et celle sur sa droite, soit une fourchette dans chaque main, afin de manger.

4. Eat -> sleep -> think

   > - D'abord, chaque philosopher doit commencer par manger
   >
   > - Quand un philosophe a fini de manger, il repose les fourchettes sur la table et se met à dormir.
   >
   > - Une fois réveillé, il se remet à penser.
   >
   > - La simulation prend fin si un philosophe meurt de faim.

5. ETC.

   > - Chaque philosophe a besoin de manger et ne doit pas mourir de faim.
   >
   > - Les philosophes ne communiquent pas entre eux.
   >
   > - Les philosophes ne peuvent pas savoir si l’un d’entre eux est sur le point de mourir.
   >
   > - Inutile de préciser que les philosophes ne doivent pas mourir !

### Program

- Arguments

  ```bash
  ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
  ```

  - number_of_philosophers : Le nombre de philosophes, mais aussi le nombre de fourchettes.

  - time_to_die (en millisecondes) :Si un philosophe n’a pas commencé à manger time_to_die millisecondes après le début de son précédent repas ou depuis le début de la simulation, il meurt.

  - time_to_eat (en millisecondes) : Le temps qu’un philosophe prend à manger. Pendant ce temps, un philosophe doit garder ses deux fourchettes.

  - time_to_sleep (en millisecondes) : Le temps qu’un philosophe passe à dormir.

  - number_of_times_each_philosopher_must_eat (argument optionnel) :
    - Si tous les philosophes ont mangé au moins number_of_times_each_philosopher_must_eat fois, la simulation prend fin.
    - Si cet argument n’est pas spécifié, alors la simulation prend fin à la mort d’un philosophe.

- Assign number to each philosophers

  - Chaque philosophe se voit assigner un numéro entre 1 et `number_of_philosophers`.

  - Le philosophe numéro 1 est assis à côté du philosophe numéro `number_of_philosophers`.

  - Les autres suivent cette logique : philosophe numéro `N` est assis entre philosophe numéro `N - 1` et philosophe numéro `N + 1`.

### Theory
