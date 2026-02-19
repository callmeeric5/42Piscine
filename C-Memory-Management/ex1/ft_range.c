/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:46:49 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/04 21:47:00 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	length;
	int	i;

	if (min >= max)
		return (NULL);
	length = max - min;
	array = (int *) malloc(length * sizeof(int));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}

/*
int	main()
{
	int *array = ft_range(10, 5);
	
	int i = 0;
	while (i < (5 - 10))
	{
		printf("%d\n",array[i]);
		i++;
	}
}
*/
