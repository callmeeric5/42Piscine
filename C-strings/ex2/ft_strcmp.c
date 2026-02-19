/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:36:10 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/07 14:44:20 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "";
	char	s2[] = "a";
	int		res_o;
	int		res_c;

	res_o = strcmp(s1, s2);
	res_c = ft_strcmp(s1, s2);
	printf("res of original func: %d\nres of my func: %d\n", res_o, res_c);
}
*/
