/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:46:57 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/17 14:47:38 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	l_depth;
	int	r_depth;

	l_depth = 0;
	r_depth = 0;
	if (!root)
		return (0);
	l_depth = btree_level_count(root->left);
	r_depth = btree_level_count(root->right);
	if (l_depth > r_depth)
		return (l_depth + 1);
	else
		return (r_depth + 1);
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

// void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *,
// 			void *))
// {
// 	if (!*root)
// 	{
// 		*root = btree_create_node(item);
// 		return ;
// 	}
// 	if (cmpf(item, (*root)->item) < 0)
// 		btree_insert_data(&((*root)->left), item, cmpf);
// 	else
// 		btree_insert_data(&((*root)->right), item, cmpf);
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
// 	printf("%d\n", btree_level_count(root));
// 	return (0);
// }
