/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:53:13 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/16 16:07:24 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	curr = *begin_list;
	prev = NULL;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*begin_list = prev;
}

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

// int	main(void)
// {
// 	t_list	*head;

// 	head = ft_create_elem("1");
// 	head->next = ft_create_elem("2");
// 	head->next->next = ft_create_elem("3");
// 	head->next->next->next = ft_create_elem("4");
// 	head->next->next->next->next = ft_create_elem("5");
// 	ft_list_reverse(&head);
// 	while (head)
// 	{
// 		printf("%s", (char *)head->data);
// 		if (head->next)
// 			printf(" -> ");
// 		head = head->next;
// 	}
// }
