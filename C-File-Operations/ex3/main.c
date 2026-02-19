/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:59:13 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/14 13:26:18 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_finish(t_tool *t)
{
	if (t->buffer_idx > 0)
		ft_display_line(t, t->buffer_idx);
	if (t->total > 0 || t->buffer_idx > 0)
	{
		if (t->mode == 'C')
			ft_put_hex(t->total + t->buffer_idx, 8);
		else
			ft_put_hex(t->total + t->buffer_idx, 7);
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	t_tool	t;
	int		i;
	int		err;

	t.total = 0;
	t.buffer_idx = 0;
	t.star = 0;
	t.mode = 0;
	i = 1;
	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'C')
	{
		t.mode = 'C';
		i = 2;
	}
	err = 0;
	if (i == argc)
		ft_hexdump(argv[0], NULL, &t);
	while (i < argc)
	{
		if (ft_hexdump(argv[0], argv[i++], &t) < 0)
			err = 1;
	}
	ft_finish(&t);
	return (err);
}
