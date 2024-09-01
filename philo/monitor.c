/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:52:50 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/26 11:05:26 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_dead(t_data **data, t_philo *philo)
{
	pthread_mutex_lock((*data)->dead_mtx);
	printf("%ld %d died\n", get_cur_time() - (*data)->time_init, philo->id);
	(*data)->dead_f = 1;
	return (0);
}

void	*monitor(void *arg)
{
	t_data	**data;
	t_philo	*cur;

	data = (t_data **)(arg);
	cur = (*data)->philos;
	while (cur->nb_philo > (*data)->philos_finished)
	{
		pthread_mutex_lock((*data)->meal_mtx);
		if (cur->nb_meals == 0)
			(*data)->philos_finished++;
		if (cur->nb_meals && get_cur_time() - (*data)->time_init
			- cur->last_meal > cur->time_to_die && !philo_dead(data, cur))
			break ;
		pthread_mutex_unlock((*data)->meal_mtx);
		cur = cur->next;
	}
	return (NULL);
}
