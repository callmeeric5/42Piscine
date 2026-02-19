/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:46:15 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/17 13:27:44 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	if (root->left)
		btree_apply_infix(root->left, applyf);
	applyf(root->item);
	if (root->right)
		btree_apply_infix(root->right, applyf);
}

// #include <stdio.h>

// void	ft_print(void *c)
// {
// 	printf("%s\n", (char *)c);
// }

// int	main(void)
// {
// 	t_btree lv2_tree_r_r = {NULL, NULL, "7"};
// 	t_btree lv2_tree_r_l = {NULL, NULL, "6"};
// 	t_btree lv2_tree_l_r = {NULL, NULL, "5"};
// 	t_btree lv2_tree_l_l = {NULL, NULL, "4"};
// 	t_btree lv1_tree_r = {&lv2_tree_r_l, &lv2_tree_r_r, "3"};
// 	t_btree lv1_tree_l = {&lv2_tree_l_l, &lv2_tree_l_r, "2"};
// 	t_btree root = {&lv1_tree_l, &lv1_tree_r, "1"};
// 	btree_apply_infix(&root, ft_print);
// }
