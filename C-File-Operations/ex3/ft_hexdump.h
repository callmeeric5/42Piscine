/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 11:39:49 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/14 13:48:34 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFFER_SIZE 16

typedef struct s_tool
{
	int		buffer_idx;
	int		total;
	int		mode;
	int		star;
	char	buffer[BUFFER_SIZE];
	char	prev[BUFFER_SIZE];
}			t_tool;

void		ft_put_hex(unsigned int n, int len);
void		ft_display_line(t_tool *t, int size);
int			ft_hexdump(char *prog, char *file, t_tool *t);
int			ft_puterror(char *prog, char *file);
void		ft_putstr(int fd, char *str);
void		ft_handle_padding(t_tool *t, int i, int size);
void		ft_put_ascii(t_tool *t, int size);

#endif
