/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:47:50 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/14 12:09:45 by ziwang           ###   ########.fr       */
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

int	ft_putnbr(char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '+'
		|| str[i] == '-')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

void	ft_putascii(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_puterror(char *program_name, char *file_name)
{
	ft_putascii(2, basename(program_name));
	write(2, ": ", 2);
	ft_putascii(2, file_name);
	write(2, ": ", 2);
	ft_putascii(2, strerror(errno));
	write(2, "\n", 1);
	return (-1);
}

int	ft_get_file_size(char *program_name, char *file_name)
{
	int		fd;
	int		byte_read;
	int		file_size;
	char	buffer[BUFFER_SIZE + 1];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_puterror(program_name, file_name));
	byte_read = 1;
	file_size = 0;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		file_size += byte_read;
	}
	if (byte_read == -1)
		return (ft_puterror(NULL, NULL));
	close(fd);
	return (file_size);
}

int	ft_open_file(char *file_name, int file_size)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (file_size < 0 || fd < 0)
		return (-1);
	return (fd);
}
