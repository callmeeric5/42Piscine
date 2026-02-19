/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:19:53 by ziwang            #+#    #+#             */
/*   Updated: 2026/01/30 14:05:54 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_combs(char *combs, int n, int pos, int start)
{
	int	i;
	int	digit;

	if (pos == n)
	{
		i = 0;
		while (i < n)
		{
			ft_putchar(combs[i++]);
		}
		if (combs[0] != '9' - n + 1)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		return ;
	}
	digit = start;
	while (digit <= 9)
	{
		combs[pos] = '0' + digit;
		print_combs(combs, n, pos + 1, digit + 1);
		digit++;
	}
}

void	ft_print_combn(int n)
{
	char	combs[10];

	print_combs(combs, n, 0, 0);
}

/*
int	main()
{
	ft_print_combn(3);
	write(1, "\n", 1);

	return 0;
}
*/
