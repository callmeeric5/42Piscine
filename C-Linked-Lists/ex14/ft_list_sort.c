/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 13:29:02 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/15 16:15:01 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *))
{
	int		swapped;
	t_list	*curr;
	void	*temp;

	if (!begin_list || !*begin_list)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		curr = *begin_list;
		while (curr && curr->next)
		{
			if (cmp(curr->data, curr->next->data) > 0)
			{
				temp = curr->data;
				curr->data = curr->next->data;
				curr->next->data = temp;
				swapped = 1;
			}
			curr = curr->next;
		}
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
// 	char	s1[] = "4";
// 	char	s2[] = "3";
// 	char	s3[] = "8";
// 	char	s4[] = "0";
// 	char	s5[] = "7";

// 	head = ft_create_elem(s1);
// 	head->next = ft_create_elem(s2);
// 	head->next->next = ft_create_elem(s3);
// 	head->next->next->next = ft_create_elem(s4);
// 	head->next->next->next->next = ft_create_elem(s5);
// 	ft_list_sort(&head, ft_strcmp);
// 	while (head)
// 	{
// 		printf("%s", (char *)head->data);
// 		if (head->next)
// 			printf(" -> ");
// 		head = head->next;
// 	}
// 	printf("\n");
// }
