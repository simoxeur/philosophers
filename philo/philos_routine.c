/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:30:48 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/29 15:34:34 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_fork_func(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->dead_mtx);
	pthread_mutex_lock(philo->write_mtx);
	printf("%ld %d has taken a fork\n", get_cur_time()
		- philo->data->time_init, philo->id);
	pthread_mutex_unlock(philo->write_mtx);
	pthread_mutex_unlock(philo->dead_mtx);
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->dead_mtx);
	pthread_mutex_lock(philo->write_mtx);
	printf("%ld %d has taken a fork\n", get_cur_time()
		- philo->data->time_init, philo->id);
	pthread_mutex_unlock(philo->write_mtx);
	pthread_mutex_unlock(philo->dead_mtx);
}

static void	eat_func(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_mtx);
	philo->last_meal = get_cur_time() - philo->data->time_init;
	pthread_mutex_lock(philo->write_mtx);
	printf("%ld %d is eating\n", get_cur_time()
		- philo->data->time_init, philo->id);
	pthread_mutex_unlock(philo->write_mtx);
	pthread_mutex_unlock(philo->meal_mtx);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_lock(philo->meal_mtx);
	--philo->nb_meals;
	pthread_mutex_unlock(philo->meal_mtx);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

static void	sleep_func(t_philo *philo)
{
	if (philo->nb_meals)
	{
		pthread_mutex_lock(philo->dead_mtx);
		pthread_mutex_lock(philo->write_mtx);
		printf("%ld %d is sleeping\n", get_cur_time()
			- philo->data->time_init, philo->id);
		pthread_mutex_unlock(philo->write_mtx);
		pthread_mutex_unlock(philo->dead_mtx);
		ft_usleep(philo->time_to_sleep);
	}
}

static void	think_func(t_philo *philo)
{
	if (philo->nb_meals)
	{
		pthread_mutex_lock(philo->dead_mtx);
		pthread_mutex_lock(philo->write_mtx);
		printf("%ld %d is thinking\n", get_cur_time()
			- philo->data->time_init, philo->id);
		pthread_mutex_unlock(philo->write_mtx);
		pthread_mutex_unlock(philo->dead_mtx);
	}
}

void	*philos_routine(void *arg)
{
	t_philo	*cur;

	cur = (t_philo *)arg;
	if (cur->id % 2 == 0)
		usleep(500);
	while (cur->nb_meals)
	{
		take_fork_func(cur);
		eat_func(cur);
		sleep_func(cur);
		think_func(cur);
	}
	return (NULL);
}
