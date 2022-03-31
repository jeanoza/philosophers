# Philosophers

## Resume

### Goal : imitate exactly `pipe` of terminal.

### Library && Function autorized

```c
/* unistd.h */
int		close(int fildes);
ssize_t read(int fildes, void *buf, size_t nbyte);
ssize_t write(int fildes, const void *buf, size_t nbyte);
int		access(const char *path, int mode);
int		dup(int fildes);
int		dup2(int fildes, int fildes2);
int		execve(const char *path, char *const argv[], char *const envp[]);
pid_t	fork(void); // create new process
int		pipe(int fildes[2]);
int		unlink(const char *path);

/* sys/wait.h */
pid_t	wait(int *stat_loc);
pid_t	waitpid(pid_t pid, int *stat_loc, int options);

/* fcntl.h */
int		open(const char *path, int oflag, ...);

/* stdlib.h */
int		malloc(size_t size);
void	free(void *ptr);
void	exit(int status);

/* stdio.h */
void	perror(const char *s);

/* string.h */
char *strerror(int errnum);

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
