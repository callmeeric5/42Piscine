/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 13:20:39 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/15 16:13:34 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*last;

	if (!*begin_list1)
		*begin_list1 = begin_list2;
	last = *begin_list1;
	while (last && last->next)
		last = last->next;
	last->next = begin_list2;
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
// 	t_list	*s1;
// 	t_list	*s2;

// 	// t_list	*s3;
// 	s1 = ft_create_elem("1");
// 	s1->next = ft_create_elem("2");
// 	s1->next->next = ft_create_elem("3");
// 	s1->next->next->next = ft_create_elem("4");
// 	s1->next->next->next->next = ft_create_elem("5");
// 	s2 = ft_create_elem("A");
// 	s2->next = ft_create_elem("B");
// 	s2->next->next = ft_create_elem("C");
// 	s2->next->next->next = ft_create_elem("D");
// 	s2->next->next->next->next = ft_create_elem("E");
// 	ft_list_merge(&s1, s2);
// 	// ft_list_merge(&s3, s2);
// 	while (s1)
// 	{
// 		printf("%s", (char *)s1->data);
// 		if (s1->next)
// 			printf(" -> ");
// 		s1 = s1->next;
// 	}
// 	printf("\n");
// }
