/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroying_mtx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:28:01 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/25 12:28:22 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroying(t_data **data)
{
	int		i;
	t_philo	*cur_philo;

	i = 0;
	cur_philo = (*data)->philos;
	while (i < cur_philo->nb_philo)
	{
		pthread_mutex_destroy(cur_philo->l_fork);
		cur_philo = cur_philo->next;
		i++;
	}
	pthread_mutex_destroy((*data)->dead_mtx);
	pthread_mutex_destroy((*data)->write_mtx);
	pthread_mutex_destroy((*data)->meal_mtx);
}
