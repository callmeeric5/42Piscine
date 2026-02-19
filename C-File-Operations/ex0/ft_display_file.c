/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:13:20 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/12 13:29:20 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

int	ft_display_file(char *file)
{
	int		fd;
	char	buffer[1024];
	int		byte_read;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (1);
		write(1, buffer, byte_read);
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int	return_value;

	return_value = 0;
	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	return_value = ft_display_file(argv[1]);
	return (return_value);
}
