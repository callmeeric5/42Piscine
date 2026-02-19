/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 04:00:47 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/05 06:20:48 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	char	*func_name;

	func_name = argv[0];
	while (*func_name && argc != 0)
	{
		ft_putchar(*func_name);
		func_name++;
	}
	ft_putchar('\n');
	return (0);
}
