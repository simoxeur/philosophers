/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:45:05 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/29 15:21:34 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*add_chair(int id, char **argv, t_allocate **head)
{
	t_philo	*philo;

	philo = (t_philo *)ft_malloc(head, sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->nb_philo = ft_arg_atoa(argv[1]);
	philo->time_to_die = ft_arg_atoa(argv[2]);
	philo->time_to_eat = ft_arg_atoa(argv[3]);
	philo->time_to_sleep = ft_arg_atoa(argv[4]);
	if (!argv[5])
		philo->nb_meals = -1;
	else
		philo->nb_meals = ft_arg_atoa(argv[5]);
	philo->l_fork = ft_malloc(head, sizeof(pthread_mutex_t));
	if (!philo->l_fork)
		return (NULL);
	philo->next = NULL;
	return (philo);
}

static int	add_philo(t_philo **philos, int id, char **argv, t_allocate **head)
{
	t_philo	*current;

	current = *philos;
	if (!*philos)
	{
		*philos = add_chair(id + 1, argv, head);
		if (!*philos)
			return (1);
	}
	else
	{
		while (current && current->next)
			current = current->next;
		current->next = add_chair(id + 1, argv, head);
		if (!current->next)
			return (1);
	}
	return (0);
}

int	set_table(t_data **data, char **argv, t_allocate **head)
{
	int		i;
	t_philo	*last;
	t_philo	**philos;

	philos = &(*data)->philos;
	i = 0;
	while (i < ft_arg_atoa(argv[1]))
	{
		if (add_philo(philos, i, argv, head))
			return (1);
		i++;
	}
	last = *philos;
	if (!last)
		return (1);
	while (last->next)
		last = last->next;
	last->next = *philos;
	return (0);
}
