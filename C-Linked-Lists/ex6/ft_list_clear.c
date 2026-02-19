/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:18:02 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/15 18:10:50 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;

	while (begin_list)
	{
		tmp = begin_list->next;
		free_fct(begin_list->data);
		free(begin_list);
		begin_list = tmp;
	}
}

// void	ft_free(void *data)
// {
// 	if (data)
// 		free(data);
// }

// t_list	*ft_create_elem(void *data)
// {
// 	t_list	*node;

// 	node = malloc(sizeof(t_list));
// 	if (!node)
// 		return (NULL);
// 	node->data = data;
// 	node->next = NULL;
// 	return (node);
// }

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	t_list	*head;

// 	head = ft_create_elem((void *)strdup("1"));
// 	head->next = ft_create_elem((void *)strdup("2"));
// 	head->next->next = ft_create_elem((void *)strdup("3"));
// 	head->next->next->next = ft_create_elem((void *)strdup("4"));
// 	head->next->next->next->next = ft_create_elem((void *)strdup("5"));
// 	ft_list_clear(head, ft_free);
// 	return (0);
// }
