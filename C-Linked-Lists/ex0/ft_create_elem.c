/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:11:34 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/15 15:13:39 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		n;
// 	t_list	*ls;

// 	n = 0;
// 	ls = ft_create_elem(&n);
// 	if (!ls)
// 		return (1);
// 	printf("%d\n", *(int *)ls->data);
// 	free(ls);
// 	return (0);
// }
