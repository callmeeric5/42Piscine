/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:20:32 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/01 14:33:26 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}
}

/*
int	main()
{
	int tab[] = {0,1,2,3,4,5,6,7,8,9};
	ft_rev_int_tab(tab, 10);
	int i = 0;
	while (i < 10)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}
*/
