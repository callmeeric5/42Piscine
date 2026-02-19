/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:30:55 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/14 12:09:55 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

int		ft_putnbr(char *str);
void	ft_putascii(int fd, char *str);
int		ft_puterror(char *program_name, char *file_name);
int		ft_get_file_size(char *program_name, char *file_name);
int		ft_tail(char *program_name, char *file_name, int n);
int		ft_open_file(char *file_name, int file_size);
int		ft_stdin(int n);
int		get_file_index(int argc, char **argv, int *n);
int		put_header(char **argv, int *i);

int	ft_tail(char *program_name, char *file_name, int n)
{
	int		file_size;
	int		pos;
	int		fd;
	int		byte_read;
	char	buffer[BUFFER_SIZE];

	file_size = ft_get_file_size(program_name, file_name);
	fd = ft_open_file(file_name, file_size);
	pos = 0;
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (pos + byte_read > file_size - n)
		{
			if (pos < file_size - n)
				write(1, buffer + (file_size - n - pos), byte_read - (file_size
						- n - pos));
			else
				write(1, buffer, byte_read);
		}
		pos += byte_read;
	}
	close(fd);
	return (file_size >= 0 && fd > 0);
}

int	ft_stdin(int n)
{
	char	*buffer;
	char	tmp[BUFFER_SIZE];
	int		byte_read;
	int		total;
	int		i;

	buffer = malloc(10000);
	if (buffer == NULL)
		return (ft_puterror(NULL, NULL));
	total = 0;
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(0, tmp, BUFFER_SIZE);
		i = 0;
		while (i < byte_read)
			buffer[total++] = tmp[i++];
	}
	if (total > n)
		write(1, buffer + total - n, n);
	else
		write(1, buffer, total);
	free(buffer);
	return (0);
}
