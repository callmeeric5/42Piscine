/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:21:15 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/03 12:39:08 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sub;
	int	is_ascend;
	int	is_descend;

	i = 0;
	is_ascend = 1;
	is_descend = 1;
	while (i < length - 1)
	{
		sub = f(tab[i], tab[i + 1]);
		if (sub > 0)
			is_ascend = 0;
		if (sub < 0)
			is_descend = 0;
		i++;
	}
	return (is_ascend || is_descend);
}

/*
int	ft_comp(int a, int b)
{
	if (a > b)
		return 1;
	if (a == b)
		return 0;
	return -1;
}

int	main()
{
	int array1[] = {1,2,3,4,5};
	int array2[] = {5,4,3,2,1};
	int array3[] = {1,1,1,1,1};
	int array4[] = {1,3,2,5,4};
	printf("res: %d\n", ft_is_sort(array1, 5, &ft_comp));
	printf("res: %d\n", ft_is_sort(array2, 5, &ft_comp));
	printf("res: %d\n", ft_is_sort(array3, 5, &ft_comp));
	printf("res: %d\n", ft_is_sort(array4, 5, &ft_comp));
}
*/
