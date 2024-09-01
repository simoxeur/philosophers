/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:30:48 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/29 10:19:43 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	take_fork_func(t_philo *philo)
{
	sem_wait(philo->sem_fork);
	sem_wait(philo->sem_print);
	printf("%ld %d has taken a fork\n", get_cur_time()
		- philo->data->time_init, philo->id);
	sem_post(philo->sem_print);
	sem_wait(philo->sem_fork);
	sem_wait(philo->sem_print);
	printf("%ld %d has taken a fork\n", get_cur_time()
		- philo->data->time_init, philo->id);
	sem_post(philo->sem_print);
}

static void	eat_func(t_philo *philo)
{
	philo->is_eating = 1;
	philo->last_meal = get_cur_time() - *philo->start_time;
	sem_wait(philo->sem_print);
	printf("%ld %d is eating\n", get_cur_time()
		- philo->data->time_init, philo->id);
	sem_post(philo->sem_print);
	ft_usleep(philo->time_to_eat);
	philo->is_eating = 0;
	sem_post(philo->sem_fork);
	sem_post(philo->sem_fork);
	philo->nb_meals--;
}

static void	sleep_func(t_philo *philo)
{
	if (philo->nb_meals)
	{
		sem_wait(philo->sem_print);
		printf("%ld %d is sleeping\n", get_cur_time()
			- philo->data->time_init, philo->id);
		sem_post(philo->sem_print);
		ft_usleep(philo->time_to_sleep);
	}
}

static void	think_func(t_philo *philo)
{
	if (philo->nb_meals)
	{
		sem_wait(philo->sem_print);
		printf("%ld %d is thinking\n", get_cur_time()
			- philo->data->time_init, philo->id);
		sem_post(philo->sem_print);
	}
}

void	*philos_routine_bonus(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->nb_meals)
	{
		take_fork_func(philo);
		eat_func(philo);
		sleep_func(philo);
		think_func(philo);
	}
	sem_close(philo->sem_fork);
	sem_close(philo->sem_print);
	exit(0);
}
