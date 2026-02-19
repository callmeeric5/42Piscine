/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:13:00 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/15 13:45:49 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*node;

	if (!begin_list)
		return (NULL);
	node = begin_list;
	while (node && node->next)
		node = node->next;
	return (node);
}

// #include <stdio.h>
// #include <stdlib.h>
// t_list	*ft_create_elem(void *data)
// {
// 	t_list	*node;

// 	node = (t_list *)malloc(sizeof(t_list));
// 	if (!node)
// 		return (NULL);
// 	node->data = data;
// 	node->next = NULL;
// 	return (node);
// }
// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*last;

// 	node1 = ft_create_elem("1");
// 	node2 = ft_create_elem("2");
// 	node3 = ft_create_elem("3");
// 	if (!node1 || !node2 || !node3)
// 		return (1);
// 	node1->next = node2;
// 	node2->next = node3;
// 	last = ft_list_last(node1);
// 	if (last)
// 		printf("%s\n", (char *)last->data);
// 	return (0);
// }
