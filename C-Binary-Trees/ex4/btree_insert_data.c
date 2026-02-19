/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:46:31 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/16 13:46:32 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *,
			void *))
{
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
		btree_insert_data(&((*root)->left), item, cmpf);
	else
		btree_insert_data(&((*root)->right), item, cmpf);
}

// #include <stdio.h>
// #include <string.h>

// int	cmp(void *s1, void *s2)
// {
// 	return (strcmp((char *)s1, (char *)s2));
// }

// t_btree	*btree_create_node(void *item)
// {
// 	t_btree	*node;

// 	node = (t_btree *)malloc(sizeof(t_btree));
// 	if (!node)
// 		return (NULL);
// 	node->item = item;
// 	node->left = NULL;
// 	node->right = NULL;
// 	return (node);
// }
// void	btree_infix(t_btree *root)
// {
// 	if (!root)
// 		return ;
// 	btree_infix(root->left);
// 	printf("%s ", (char *)root->item);
// 	btree_infix(root->right);
// }
// int	main(void)
// {
// 	t_btree *root = NULL;
// 	btree_insert_data(&root, "4", cmp);
// 	btree_insert_data(&root, "2", cmp);
// 	btree_insert_data(&root, "6", cmp);
// 	btree_insert_data(&root, "1", cmp);
// 	btree_insert_data(&root, "3", cmp);
// 	btree_insert_data(&root, "5", cmp);
// 	btree_insert_data(&root, "7", cmp);
// 	btree_infix(root);
// 	return (0);
// }
