/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:07:01 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/14 13:47:39 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_put_hex(unsigned int n, int len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (len > 1)
		ft_put_hex(n / 16, len - 1);
	write(1, &hex[n % 16], 1);
}

void	ft_putstr(int fd, char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_puterror(char *prog, char *file)
{
	ft_putstr(2, basename(prog));
	ft_putstr(2, ": ");
	if (file)
	{
		ft_putstr(2, file);
		ft_putstr(2, ": ");
	}
	ft_putstr(2, strerror(errno));
	write(2, "\n", 1);
	return (-1);
}

void	ft_handle_padding(t_tool *t, int i, int size)
{
	if (t->mode == 'C')
	{
		while (i < 16)
		{
			write(1, "   ", 3);
			if (i == 7)
				write(1, " ", 1);
			i++;
		}
	}
	ft_put_ascii(t, size);
	write(1, "\n", 1);
	i = -1;
	while (++i < 16)
		t->prev[i] = t->buffer[i];
}
