/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:48:48 by ziwang            #+#    #+#             */
/*   Updated: 2026/01/30 13:34:47 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchr(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchr('-');
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchr('0' + nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

/*
int main()
{
	//0-9 digits
	ft_putnbr(3);
	write(1, "\n", 1);
	//negative number
	ft_putnbr(-42);
	write(1, "\n", 1);
	//positive number
	ft_putnbr(42);
	write(1, "\n", 1);
	//minimum number
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	//maximum number
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	return 0;
}
*/
