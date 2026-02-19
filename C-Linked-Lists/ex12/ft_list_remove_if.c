/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:34:15 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/16 16:27:07 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(void *, void *), void (*free_fct)(void *))
{
	t_list	*curr;
	t_list	*tmp;

	if (!*begin_list)
		return ;
	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free_fct(tmp->data);
		free(tmp);
	}
	curr = *begin_list;
	while (curr && curr->next)
	{
		if (cmp(curr->next->data, data_ref) == 0)
		{
			tmp = curr->next;
			curr->next = tmp->next;
			free_fct(tmp->data);
			free(tmp);
		}
		else
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

// void	ft_free(void *data)
// {
// 	(void) data;
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
// 	ft_list_remove_if(&head, ref, ft_strcmp, ft_free);
// 	while (head)
// 	{
// 		printf("%s", (char *)head->data);
// 		if (head->next)
// 			printf(" -> ");
// 		head = head->next;
// 	}
// }
