/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:29:27 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/26 10:47:24 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	link_ptr(t_data **data)
{
	int		i;
	t_philo	*cur_philo;

	i = 0;
	cur_philo = (*data)->philos;
	while (i < cur_philo->nb_philo)
	{
		cur_philo->data = *data;
		cur_philo->sem_fork = (*data)->chopsticks;
		cur_philo->sem_print = (*data)->print_sem;
		cur_philo->start_time = &(*data)->time_init;
		cur_philo = cur_philo->next;
		i++;
	}
}

int	data_init(t_data **data, char **argv, t_allocate **head)
{
	(*data)->philos = NULL;
	(*data)->time_init = get_cur_time();
	sem_unlink("/sem");
	sem_unlink("/dead");
	if (set_table(data, argv, head))
		return (1);
	(*data)->chopsticks = sem_open("/sem", O_CREAT | O_EXCL, 0644,
			(*data)->philos->nb_philo);
	(*data)->print_sem = sem_open("/dead", O_CREAT | O_EXCL, 0644, 1);
	if (!(*data)->chopsticks || !(*data)->print_sem)
		return (1);
	link_ptr(data);
	return (0);
}
