/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 13:42:05 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/15 17:36:47 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_swap_data(t_list *left, t_list *right)
{
	void	*tmp;

	tmp = left->data;
	left->data = right->data;
	right->data = tmp;
}

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

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*current;

	if (!begin_list)
		return (NULL);
	i = 0;
	current = begin_list;
	while (i < nbr)
	{
		if (!current)
			return (NULL);
		current = current->next;
		i++;
	}
	return (current);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	t_list	*left_node;
	t_list	*right_node;
	int		i;

	size = ft_list_size(begin_list);
	i = 0;
	while (i < size / 2)
	{
		left_node = ft_list_at(begin_list, i);
		right_node = ft_list_at(begin_list, size - 1 - i);
		ft_list_swap_data(left_node, right_node);
		i++;
	}
}

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

// 	head = ft_create_elem("1");
// 	head->next = ft_create_elem("2");
// 	head->next->next = ft_create_elem("3");
// 	head->next->next->next = ft_create_elem("4");
// 	head->next->next->next->next = ft_create_elem("5");
// 	ft_list_reverse_fun(head);
// 	while (head)
// 	{
// 		printf("%s", (char *)head->data);
// 		if (head->next)
// 			printf(" -> ");
// 		head = head->next;
// 	}
// }
