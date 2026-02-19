/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:03:47 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/16 13:47:44 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*node;

	node = (t_btree *)malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node->item = item;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_btree	*btree;

// 	btree = btree_create_node("0");
// 	printf("val: %s\n", (char *)btree->item);
// 	printf("left: %p\n", (void *)btree->left);
// 	printf("right: %p\n", (void *)btree->right);
// }
