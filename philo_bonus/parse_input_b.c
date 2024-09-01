/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:38:52 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/29 16:04:17 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_err(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!av[i] || !*av[i])
			return (1);
		if (ft_arg_atoa(av[i]) < 0)
			return (1);
	}
	return (0);
}

void	ft_error(void)
{
	write(2, "\x1b[31mERROR\n\x1b[32musage: ./philo_bonus number_of_philosophers \
time_to_die time_to_eat time_to_sleep \
number_of_times_each_philosopher_must_eat\n\
\033[0;37m|!| the last argument is optional \
and make sure the argument of time are positive numbers\n", 237);
}
