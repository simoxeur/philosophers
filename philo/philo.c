/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:41:20 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/29 16:10:24 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_allocate	*head;
	t_data		*data;

	head = NULL;
	data = (t_data *)ft_malloc(&head, sizeof(t_data));
	if (!data)
		return (1);
	if ((argc != 5 && argc != 6) || check_err(argc, argv))
		return (clean_up(&head), ft_error(), 1);
	if (data_init(&data, argv, &head))
		return (clean_up(&head), 1);
	if (threads_creation(&data))
		return (clean_up(&head), 1);
	ft_destroying(&data);
	clean_up(&head);
	return (0);
}
