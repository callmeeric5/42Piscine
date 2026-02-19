/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:23:36 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/15 15:57:43 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*curr;

	if (!begin_list)
		return ;
	curr = begin_list;
	while (curr)
	{
		f(curr->data);
		curr = curr->next;
	}
}

// void	increase(void *data)
// {
// 	*(int *)data += 1;
// }

// #include <stdio.h>

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
// 	int		a = 1, b = 2, c = 3, d = 4, e;

// 	a = 1, b = 2, c = 3, d = 4, e = 5;
// 	head = ft_create_elem(&a);
// 	head->next = ft_create_elem(&b);
// 	head->next->next = ft_create_elem(&c);
// 	head->next->next->next = ft_create_elem(&d);
// 	head->next->next->next->next = ft_create_elem(&e);
// 	ft_list_foreach(head, &increase);
// 	while (head)
// 	{
// 		printf("%d", *(int *)head->data);
// 		if (head->next)
// 			printf(" -> ");
// 		head = head->next;
// 	}
// }
