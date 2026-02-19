/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:15:48 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/14 13:47:34 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	ft_is_equal(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_put_ascii(t_tool *t, int size)
{
	int	i;

	if (t->mode != 'C')
		return ;
	write(1, "  |", 3);
	i = 0;
	while (i < size)
	{
		if ((unsigned char)t->buffer[i] >= 32
			&& (unsigned char)t->buffer[i] <= 126)
			write(1, &t->buffer[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|", 1);
}

void	ft_print_content(t_tool *t, int size)
{
	int	i;

	i = 0;
	while (i < 16 && i < size)
	{
		if (t->mode == 'C' || i % 2 == 0)
			write(1, " ", 1);
		if (t->mode == 'C' && i == 8)
			write(1, " ", 1);
		if (t->mode == 'C')
			ft_put_hex((unsigned char)t->buffer[i], 2);
		else if (i + 1 < size)
		{
			ft_put_hex((unsigned char)t->buffer[i + 1], 2);
			ft_put_hex((unsigned char)t->buffer[i], 2);
			i++;
		}
		else
		{
			write(1, "00", 2);
			ft_put_hex((unsigned char)t->buffer[i], 2);
		}
		i++;
	}
	ft_handle_padding(t, i, size);
}

void	ft_display_line(t_tool *t, int size)
{
	if (t->total > 0 && size == 16 && ft_is_equal(t->buffer, t->prev, 16))
	{
		if (t->star == 0)
			write(1, "*\n", 2);
		t->star = 1;
		return ;
	}
	t->star = 0;
	if (t->mode == 'C')
	{
		ft_put_hex(t->total, 8);
		write(1, " ", 1);
	}
	else
		ft_put_hex(t->total, 7);
	ft_print_content(t, size);
}

int	ft_hexdump(char *prog, char *file, t_tool *t)
{
	int		fd;
	int		ret;
	char	c;

	fd = 0;
	if (file != NULL)
		fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_puterror(prog, file));
	ret = read(fd, &c, 1);
	while (ret > 0)
	{
		t->buffer[t->buffer_idx++] = c;
		if (t->buffer_idx == 16)
		{
			ft_display_line(t, 16);
			t->total += 16;
			t->buffer_idx = 0;
		}
		ret = read(fd, &c, 1);
	}
	if (fd > 0)
		close(fd);
	return (ret);
}
