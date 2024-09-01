/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:49:33 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/26 11:50:18 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	philos_handle(t_data **data, t_philo *cur_philo)
{
	static int	check = 0;

	if (cur_philo->id == 1 && check)
		return ;
	if (cur_philo->id == 1 && check == 0)
		check++;
	cur_philo->pid = fork();
	if (cur_philo->pid == -1)
	{
		write (2, "fork failed\n", 12);
		exit(2);
	}
	else if (cur_philo->pid == 0)
		thread_child(cur_philo);
	else
		philos_handle(data, cur_philo->next);
}

static int	ft_wait_proc(t_data **data, int *status)
{
	t_philo	*philo;

	philo = (*data)->philos;
	while (1)
	{
		while (waitpid(philo->pid, status, WNOHANG) != -1)
			philo = philo->next;
		if (WEXITSTATUS(*status) == 0)
		{
			while (waitpid((*data)->main_pid, status, WNOHANG) != -1)
				continue ;
			break ;
		}
		else if (WEXITSTATUS(*status) == 1)
			break ;
		else if (WEXITSTATUS(*status) == 2)
			return (1);
	}
	return (0);
}

int	process_handle(t_data **data)
{
	int		i;
	int		status;
	t_philo	*cur;

	i = -1;
	cur = (*data)->philos;
	philos_handle(data, (*data)->philos);
	if (ft_wait_proc(data, &status))
		return (1);
	while (++i < cur->nb_philo)
	{
		kill(cur->pid, SIGTERM);
		cur = cur->next;
	}
	sem_close((*data)->chopsticks);
	sem_close((*data)->print_sem);
	sem_unlink("/sem");
	sem_unlink("/dead");
	return (0);
}
