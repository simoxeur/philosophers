/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:23:28 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/25 12:38:11 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	wait_threads(t_data **data)
{
	int		i;
	int		nb_philos;
	t_philo	*current;

	i = 0;
	current = (*data)->philos;
	nb_philos = current->nb_philo;
	if (pthread_join((*data)->monitor_th, NULL))
		return (1);
	while (i < nb_philos && (*data)->dead_f == 0)
	{
		if (pthread_join(current->th, NULL))
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}

int	threads_creation(t_data **data)
{
	int		i;
	int		philo_nb;
	t_philo	*current;

	i = 0;
	current = (*data)->philos;
	philo_nb = current->nb_philo;
	if (pthread_create(&(*data)->monitor_th, NULL, monitor, (void *)data))
		return (1);
	while (i < philo_nb)
	{
		if (pthread_create(&current->th, NULL,
				philos_routine, (void *)(current)))
			return (1);
		current = current->next;
		i++;
	}
	wait_threads(data);
	return (0);
}
