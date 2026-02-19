/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:34:31 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/01 15:01:56 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *tab, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	i = low;
	j = high;
	pivot = tab[low];
	while (1)
	{
		while (tab[i] < pivot)
			i++;
		while (tab[j] > pivot)
			j--;
		if (i >= j)
			return (j);
		swap(&tab[i], &tab[j]);
		i++;
		j--;
	}
}

void	quicksort(int *tab, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(tab, low, high);
		quicksort(tab, low, pi);
		quicksort(tab, pi + 1, high);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	if (size > 1)
	{
		quicksort(tab, 0, size - 1);
	}
}

/*
int main()
{
	int arr[] = {3,2,44,12,14,67,45,22};
	int size = sizeof(arr) / sizeof (arr[0]);
	ft_sort_int_tab(arr,  size);
	for (int i=0; i<size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
*/
