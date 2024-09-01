/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:31:50 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/25 12:32:19 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_forks(t_data **data)
{
	int		i;
	int		nb_philos;
	t_philo	*cur_philo;
	t_philo	*next_philo;

	cur_philo = (*data)->philos;
	i = 0;
	nb_philos = (*data)->philos->nb_philo;
	while (i < nb_philos)
	{
		if (pthread_mutex_init(cur_philo->l_fork, NULL) != 0)
			return (1);
		cur_philo = cur_philo->next;
		i++;
	}
	i = 0;
	cur_philo = (*data)->philos;
	next_philo = (*data)->philos->next;
	while (i++ < nb_philos)
	{
		cur_philo->r_fork = next_philo->l_fork;
		cur_philo = next_philo;
		next_philo = next_philo->next;
	}
	return (0);
}
