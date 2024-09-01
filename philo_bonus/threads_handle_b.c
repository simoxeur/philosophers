/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_handle_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:51:36 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/26 11:46:47 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	thread_child(t_philo *philo)
{
	if (pthread_create(&philo->monitor_th, NULL, check_dead, philo))
		exit(2);
	if (pthread_create(&philo->routine_th, NULL, philos_routine_bonus, philo))
		exit(2);
	if (pthread_join(philo->monitor_th, NULL))
		exit(2);
	if (pthread_join(philo->routine_th, NULL))
		exit(2);
}
