/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:41:28 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/26 11:14:11 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	pthread_t		th;
	int				nb_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			last_meal;
	int				nb_meals;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*dead_mtx;
	pthread_mutex_t	*write_mtx;
	pthread_mutex_t	*meal_mtx;
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
	int				dead_f;
	int				exit_f;
	int				philos_finished;
	size_t			time_init;
	pthread_t		monitor_th;
	pthread_mutex_t	*dead_mtx;
	pthread_mutex_t	*write_mtx;
	pthread_mutex_t	*meal_mtx;
	pthread_mutex_t	*l_mtx;
	t_allocate		*allocate_session;
	t_philo			*philos;
}	t_data;

int		ft_arg_atoa(char *str);
int		check_err(int ac, char **av);
void	ft_error(void);
int		set_table(t_data **data, char **argv, t_allocate **head);
int		set_forks(t_data **data);
int		data_init(t_data **data, char **argv, t_allocate **head);
int		threads_creation(t_data **data);
void	*philos_routine(void *arg);
void	*monitor(void *arg);
size_t	get_cur_time(void);
int		ft_usleep(size_t time_tosleep);
void	*ft_malloc(t_allocate **lst_ptr, size_t size);
void	ft_destroying(t_data **data);
void	clean_up(t_allocate **lst_ptr);

#endif