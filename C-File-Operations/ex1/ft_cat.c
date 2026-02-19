/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:56:13 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/12 18:27:10 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

void	ft_putascii(int fd, char *str);
int		ft_puterror(char *program_name, char *file_name);
int		ft_stdin(void);
int		ft_cat(char *program_name, char *file_name);

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
	return (1);
}

int	ft_stdin(void)
{
	char	buffer[BUFFER_SIZE + 1];
	int		byte_read;
	int		exit_code;

	byte_read = 1;
	exit_code = 0;
	while (byte_read > 0)
	{
		byte_read = read(0, buffer, BUFFER_SIZE);
		buffer[byte_read] = '\0';
		ft_putascii(1, buffer);
	}
	if (byte_read == -1)
		exit_code = ft_puterror(NULL, NULL);
	return (exit_code);
}

int	ft_cat(char *program_name, char *file_name)
{
	int		fd;
	int		byte_read;
	char	buffer[BUFFER_SIZE + 1];
	int		exit_code;

	exit_code = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_puterror(program_name, file_name));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_read] = '\0';
		ft_putascii(1, buffer);
	}
	if (byte_read == -1)
		exit_code = ft_puterror(program_name, file_name);
	close(fd);
	return (exit_code);
}
