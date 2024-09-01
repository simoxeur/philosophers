/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:16:42 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/26 10:19:31 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	if (process_handle(&data))
		return (clean_up(&head), 1);
	clean_up(&head);
	return (0);
}
