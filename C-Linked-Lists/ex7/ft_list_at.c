/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:12:16 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/15 16:07:02 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*node;

// 	head = ft_create_elem("1");
// 	head->next = ft_create_elem("2");
// 	head->next->next = ft_create_elem("3");
// 	head->next->next->next = ft_create_elem("4");
// 	head->next->next->next->next = ft_create_elem("5");
// 	node = ft_list_at(head, (unsigned int) 3);
// 	printf("%s\n", (char *)node->data);
// }
