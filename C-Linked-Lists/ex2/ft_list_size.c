/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:12:12 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/15 15:18:48 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

// #include <stdio.h>

// t_list	*ft_create_elem(void *data)
// {
// 	t_list	*node;

// 	node = (t_list *)malloc(sizeof(t_list));
// 	node->data = data;
// 	node->next = NULL;
// 	return (node);
// }

// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;

// 	node1 = ft_create_elem("1");
// 	node2 = ft_create_elem("2");
// 	node3 = ft_create_elem("3");
// 	node1->next = node2;
// 	node2->next = node3;
// 	printf("%d\n", ft_list_size(node1));
// }
