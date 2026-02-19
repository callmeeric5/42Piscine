/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:46:53 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/15 16:10:21 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)(void *, void *))
{
	t_list	*curr;

	if (!begin_list)
		return ;
	curr = begin_list;
	while (curr)
	{
		if (cmp(curr->data, data_ref) == 0)
			f(curr->data);
		curr = curr->next;
	}
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

// void	ft_uppercase(void *s)
// {
// 	char	*str;
// 	int		i;

// 	i = 0;
// 	str = (char *)s;
// 	while (str[i])
// 	{
// 		if (str[i] >= 'a' && str[i] <= 'z')
// 			str[i] -= 32;
// 		i++;
// 	}
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
// 	char	s1[] = "hello";
// 	char	s2[] = "world";
// 	char	s3[] = "I";
// 	char	s4[] = "am";
// 	char	s5[] = "Snnopy";
// 	char	*ref;

// 	ref = "Snnopy";
// 	head = ft_create_elem(s1);
// 	head->next = ft_create_elem(s2);
// 	head->next->next = ft_create_elem(s3);
// 	head->next->next->next = ft_create_elem(s4);
// 	head->next->next->next->next = ft_create_elem(s5);
// 	ft_list_foreach_if(head, ft_uppercase, (void *)ref, ft_strcmp);
// 	while (head)
// 	{
// 		printf("%s", (char *)head->data);
// 		if (head->next)
// 			printf(" -> ");
// 		head = head->next;
// 	}
// }
