/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:01:27 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/04 23:48:23 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	length;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	length = max - min;
	*range = (int *)malloc(length * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < length)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}

/*
int	main()
{
	int	*nums;
	int	length = ft_ultimate_range(&nums, 2, 3);
	int	i = 0;
	printf("size: %d\n", length);
	while (i < length)
	{
		printf("%d\n", nums[i]);
		i++;
	}
}
*/
