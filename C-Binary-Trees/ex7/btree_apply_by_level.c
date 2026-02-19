/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:47:11 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/17 14:49:54 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	enqueue(t_list **head, t_list **tail, t_btree *node, int level)
{
	t_list	*new;

	if (!node)
		return ;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	new->node = node;
	new->next = NULL;
	new->level = level;
	if (!*head)
		*head = new;
	else
		(*tail)->next = new;
	*tail = new;
}

t_btree	*dequeue(t_list **head, int *level)
{
	t_list	*tmp;
	t_btree	*node;

	if (!*head)
		return (NULL);
	tmp = *head;
	node = tmp->node;
	*level = tmp->level;
	*head = (*head)->next;
	free(tmp);
	return (node);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_list	*head;
	t_list	*tail;
	int		level;
	int		last_level;
	t_btree	*curr;

	head = NULL;
	tail = NULL;
	last_level = -1;
	if (!root)
		return ;
	enqueue(&head, &tail, root, 0);
	while (head)
	{
		curr = dequeue(&head, &level);
		applyf(curr->item, level, (level > last_level));
		if (level > last_level)
			last_level = level;
		if (curr->left)
			enqueue(&head, &tail, curr->left, (level + 1));
		if (curr->right)
			enqueue(&head, &tail, curr->right, (level + 1));
	}
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

// void	print_node(void *item, int current_level, int is_first_elem)
// {
// 	if (is_first_elem)
// 	{
// 		printf("Level [%d]: ", current_level);
// 	}
// 	printf("%s ", (char *)item);
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
// 	t_btree	*root;

// 	root = NULL;
// 	btree_insert_data(&root, "4", cmp);
// 	btree_insert_data(&root, "2", cmp);
// 	btree_insert_data(&root, "6", cmp);
// 	btree_insert_data(&root, "1", cmp);
// 	btree_insert_data(&root, "3", cmp);
// 	btree_insert_data(&root, "5", cmp);
// 	btree_insert_data(&root, "7", cmp);
// 	btree_apply_by_level(root, print_node);
// 	return (0);
// }
