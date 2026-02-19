/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:05:41 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/02 19:57:44 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*array;

	array = malloc(length * sizeof(int));
	if (array == NULL)
	{
		return (0);
	}
	i = 0;
	while (i < length)
	{
		array[i] = f(tab[i]);
		i++;
	}
	return (array);
}

/*
int	ft_putnbr(int nbr)
{
	nbr++;
	return nbr;
}

int	main()
{
	int array[] = {1, 2, 3, 4, 5, 6};
	int *res_array = ft_map(array, 6, &ft_putnbr);
	int i = 0;
	while (i < 6)
	{
		printf("%d\n", res_array[i]);
		i++;
	}
}
*/
