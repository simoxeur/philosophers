/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:15:00 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/29 14:20:23 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_dead(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		ft_usleep(3);
		if (philo->nb_meals && (get_cur_time() - philo->data->time_init
				- philo->last_meal) > philo->time_to_die)
		{
			if (philo->is_eating == 0)
			{
				sem_wait(philo->sem_print);
				printf("%ld %d died\n", (get_cur_time()
						- *philo->start_time), philo->id);
				exit(1);
			}
		}
	}
	return (NULL);
}
