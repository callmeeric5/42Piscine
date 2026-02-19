/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:42:31 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/07 18:48:21 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_get_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_str_copy(char *str)
{
	int		i;
	int		len;
	char	*res;

	len = ft_get_len(str);
	res = malloc(len * sizeof(char) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*res;

	res = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		res[i].size = ft_get_len(av[i]);
		res[i].str = av[i];
		res[i].copy = ft_str_copy(av[i]);
		i++;
	}
	res[i].str = 0;
	return (res);
}

/*
#include <stdio.h>

int	main(void)
{
	char		*arr[] = {"aissam", "abouqassime"};
	t_stock_str	*w;
	int			i;

	w = ft_strs_to_tab(2, arr);
	i = 0;
	while (w[i].str)
	{
		printf("%s\n", w[i].copy);
		i++;
	}
	return (0);
}
*/
