/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:46:07 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/12 18:27:15 by ziwang           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	*program_name;
	char	*file_name;
	int		i;
	int		exit_code;

	exit_code = 0;
	if (argc == 1)
		exit_code = ft_stdin();
	else
	{
		program_name = argv[0];
		i = 1;
		while (i < argc)
		{
			file_name = argv[i];
			exit_code = ft_cat(program_name, file_name);
			i++;
		}
	}
	return (exit_code);
}
