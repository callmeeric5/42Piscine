/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:31:48 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/14 12:09:50 by ziwang           ###   ########.fr       */
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

int	get_file_index(int argc, char **argv, int *n)
{
	int	i;

	i = 1;
	*n = 10;
	while (i < argc && argv[i][0] == '-')
	{
		if (argv[i][1] == 'c')
		{
			if (argv[i][2])
				*n = ft_putnbr(&argv[i][2]);
			else if (i + 1 < argc)
				*n = ft_putnbr(argv[++i]);
		}
		i++;
	}
	return (i);
}

int	put_header(char **argv, int *i)
{
	if (open(argv[*i], O_RDONLY) > 0)
	{
		write(1, "==> ", 4);
		ft_putascii(1, argv[*i]);
		write(1, " <==\n", 5);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	n;
	int	i;
	int	exit_code;

	exit_code = 0;
	i = get_file_index(argc, argv, &n);
	if (i >= argc)
		return (ft_stdin(n));
	else
	{
		while (i < argc)
		{
			if (argc > 4)
			{
				put_header(argv, &i);
				exit_code = ft_tail(argv[0], argv[i], n);
				if (i < argc - 1 && exit_code > 0)
					write(1, "\n", 1);
			}
			else
				exit_code = ft_tail(argv[0], argv[i], n);
			i++;
		}
	}
	return (exit_code == 0);
}
