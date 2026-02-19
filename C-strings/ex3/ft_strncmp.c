/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:48:39 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/07 14:44:50 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || !s1[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "apple21321";
	char	s2[] = "apple13242";
	int		res_o;
	int		res_c;
	int		n;

	n = 10;
	res_o = strncmp(s1, s2, n);
	res_c = ft_strncmp(s1, s2, n);
	printf("res of original func: %d\nres of my func: %d\n", res_o, res_c);
}
*/
