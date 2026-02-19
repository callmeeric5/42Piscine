/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:24:22 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/01 19:28:46 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/*
int	main()
{
	char *str1 = "abcdefghijklmnopqrstuvwxyz";
	char *str2 = "4312432153254";
	char *str3 = "ABC132";
	char *str4 = "  AB";
	char *str5 = "";
	ft_putstr(str1);
	write(1, "\n", 1);
	ft_putstr(str2);
	write(1, "\n", 1);
	ft_putstr(str3);
	write(1, "\n", 1);
	ft_putstr(str4);
	write(1, "\n", 1);
	ft_putstr(str5);
	write(1, "\n", 1);
}
*/
