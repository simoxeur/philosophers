/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:43:49 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/29 10:19:12 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_philo
{
	pid_t			pid;
	pthread_t		monitor_th;
	pthread_t		routine_th;
	int				id;
	int				nb_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	_Atomic int		nb_meals;
	_Atomic size_t	last_meal;
	_Atomic int		is_eating;
	size_t			*start_time;
	sem_t			*sem_fork;
	sem_t			*sem_print;
	struct s_data	*data;
	struct s_philo	*next;
}	t_philo;

typedef struct s_allocate
{
	void				*ptr;
	struct s_allocate	*next;
}	t_allocate;

typedef struct s_data
{
	pid_t	main_pid;
	size_t	time_init;
	sem_t	*chopsticks;
	sem_t	*print_sem;
	t_philo	*philos;
}	t_data;

int		ft_arg_atoa(char *str);
int		data_init(t_data **data, char **argv, t_allocate **head);
int		set_table(t_data **data, char **argv, t_allocate **head);
int		process_handle(t_data **data);
void	thread_child(t_philo *philo);
void	*check_dead(void *arg);
void	*philos_routine_bonus(void *arg);
size_t	get_cur_time(void);
int		ft_usleep(size_t time_tosleep);
int		check_err(int ac, char **av);
void	ft_error(void);
void	*ft_malloc(t_allocate **lst_ptr, size_t size);
void	clean_up(t_allocate **lst_ptr);

#endif