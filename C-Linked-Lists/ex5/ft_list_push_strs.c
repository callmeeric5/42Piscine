/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:14:57 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/15 16:59:21 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*node;
	t_list	*current;

	if (!begin_list)
		return ;
	node = ft_create_elem(data);
	if (!node)
		return ;
	if (!*begin_list)
	{
		*begin_list = node;
		return ;
	}
	current = *begin_list;
	while (current && current->next)
		current = current->next;
	current->next = node;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*head;

	if (size <= 0 || !strs)
		return (NULL);
	head = NULL;
	size--;
	while (size >= 0)
	{
		ft_list_push_back(&head, strs[size]);
		size--;
	}
	return (head);
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
// 	char	*strs[3] = {"1", "2", "3"};

// 	head = ft_list_push_strs(3, strs);
// 	while (head)
// 	{
// 		printf("%s\n", (char *)head->data);
// 		head = head->next;
// 	}
// }
