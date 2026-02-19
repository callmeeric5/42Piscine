/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 14:13:19 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/17 16:06:21 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_sorted_merge(t_list *s1, t_list *s2, int (*cmp)(void *, void *))
{
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	if (cmp(s1->data, s2->data) <= 0)
	{
		s1->next = ft_sorted_merge(s1->next, s2, cmp);
		return (s1);
	}
	else
	{
		s2->next = ft_sorted_merge(s1, s2->next, cmp);
		return (s2);
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)(void *, void *))
{
	if (!begin_list1)
		return ;
	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	if (!begin_list2)
		return ;
	if (*begin_list1 == begin_list2)
		return ;
	*begin_list1 = ft_sorted_merge(*begin_list1, begin_list2, cmp);
}
// int	ft_strcmp(void *s1, void *s2)
// {
// 	char	*str1;
// 	char	*str2;
// 	int		i;

// 	str1 = (char *)s1;
// 	str2 = (char *)s2;
// 	i = 0;
// 	while (str1[i] == str2[i] && str1[i])
// 		i++;
// 	return (str1[i] - str2[i]);
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
// 	t_list	*s1;
// 	t_list	*s2;
// 	t_list	*s3;

// 	s1 = ft_create_elem("1");
// 	s1->next = ft_create_elem("2");
// 	s1->next->next = ft_create_elem("3");
// 	s1->next->next->next = ft_create_elem("4");
// 	s1->next->next->next->next = ft_create_elem("5");
// 	s2 = ft_create_elem("-1");
// 	s2->next = ft_create_elem("-2");
// 	s2->next->next = ft_create_elem("-3");
// 	s2->next->next->next = ft_create_elem("-4");
// 	s2->next->next->next->next = ft_create_elem("-5");
// 	ft_sorted_list_merge(&s1, s2, ft_strcmp);
// 	ft_sorted_list_merge(&s3, s2, ft_strcmp);
// 	while (s1)
// 	{
// 		printf("%s", (char *)s1->data);
// 		if (s1->next)
// 			printf(" -> ");
// 		s1 = s1->next;
// 	}
// 	printf("\n");
// }
