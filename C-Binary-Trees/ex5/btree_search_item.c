/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:46:46 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/17 14:53:37 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *,
			void *))
{
	void	*res;

	if (!root)
		return (NULL);
	res = btree_search_item(root->left, data_ref, cmpf);
	if (res)
		return (res);
	if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	return (btree_search_item(root->right, data_ref, cmpf));
}

#include <stdio.h>
#include <string.h>

int	cmp(void *s1, void *s2)
{
	return (strcmp((char *)s1, (char *)s2));
}

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

void	btree_infix(t_btree *root)
{
	if (!root)
		return ;
	btree_infix(root->left);
	printf("%s ", (char *)root->item);
	btree_infix(root->right);
}
int	main(void)
{
	t_btree	*root;
	void	*res;

	root = NULL;
	btree_insert_data(&root, "4", cmp);
	btree_insert_data(&root, "2", cmp);
	btree_insert_data(&root, "6", cmp);
	btree_insert_data(&root, "1", cmp);
	btree_insert_data(&root, "3", cmp);
	btree_insert_data(&root, "5", cmp);
	btree_insert_data(&root, "7", cmp);
	res = btree_search_item(root, "3", cmp);
	if (res)
		printf("%s\n", (char *)res);
	else
		printf("%p\n", res);
	return (0);
}
