/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:29:27 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/25 12:33:40 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_ptr_data(t_data **data)
{
	int		i;
	int		nb_philo;
	t_philo	*cur_philo;

	cur_philo = (*data)->philos;
	nb_philo = cur_philo->nb_philo;
	i = 0;
	while (i < nb_philo)
	{
		cur_philo->dead_mtx = (*data)->dead_mtx;
		cur_philo->write_mtx = (*data)->write_mtx;
		cur_philo->meal_mtx = (*data)->meal_mtx;
		cur_philo->data = *data;
		cur_philo = cur_philo->next;
		i++;
	}
}

int	data_init(t_data **data, char **argv, t_allocate **head)
{
	(*data)->time_init = get_cur_time();
	(*data)->dead_mtx = ft_malloc(head, sizeof(pthread_mutex_t));
	(*data)->write_mtx = ft_malloc(head, sizeof(pthread_mutex_t));
	(*data)->meal_mtx = ft_malloc(head, sizeof(pthread_mutex_t));
	if (!(*data)->dead_mtx || !(*data)->write_mtx || !(*data)->meal_mtx)
		return (1);
	if (pthread_mutex_init((*data)->dead_mtx, NULL) != 0)
		return (1);
	if (pthread_mutex_init((*data)->write_mtx, NULL) != 0)
		return (1);
	if (pthread_mutex_init((*data)->meal_mtx, NULL) != 0)
		return (1);
	(*data)->dead_f = 0;
	(*data)->philos_finished = 0;
	(*data)->philos = NULL;
	if (set_table(data, argv, head))
		return (1);
	set_ptr_data(data);
	if (set_forks(data))
		return (1);
	return (0);
}
