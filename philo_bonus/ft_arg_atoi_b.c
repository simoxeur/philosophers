/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_atoi_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:22:38 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/29 15:45:40 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_arg_atoa(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-' || !str[i])
			return (-1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		else
			return (-2);
		i++;
	}
	return (res);
}
