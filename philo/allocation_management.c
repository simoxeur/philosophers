/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:13:10 by mtalbi            #+#    #+#             */
/*   Updated: 2024/08/25 12:51:40 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_allocate	*add_node(void *ptr)
{
	t_allocate	*new_node;

	new_node = (t_allocate *)malloc(sizeof(t_allocate));
	if (!new_node)
		return (NULL);
	new_node->ptr = ptr;
	new_node->next = NULL;
	return (new_node);
}

static void	add_addr(t_allocate **head, void *new_ptr)
{
	t_allocate	*new;
	t_allocate	*last;

	new = add_node(new_ptr);
	if (!new)
		return ;
	if (!*head)
		*head = new;
	else
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return ;
}

void	*ft_malloc(t_allocate **lst_ptr, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	add_addr(lst_ptr, ptr);
	return (ptr);
}

void	clean_up(t_allocate **lst_ptr)
{
	t_allocate	*cur_ptr;
	t_allocate	*tmp;

	cur_ptr = *lst_ptr;
	while (cur_ptr)
	{
		free(cur_ptr->ptr);
		tmp = cur_ptr;
		cur_ptr = cur_ptr->next;
		free(tmp);
	}
}
