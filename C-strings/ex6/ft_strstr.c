/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 10:54:43 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/07 14:46:11 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (!to_find[0])
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && to_find[j] && str[i + j] == to_find[j])
		{
			j++;
			if (!to_find[j])
				return (str + i);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	pattern[] = "test";

	char	test[] = "La fonction strstr recherche la première
	occurrence d'une sous-chaîne (paramètre substring) dans la chaîne de
	caractères principale (paramètre fullString). ";
	printf("res of original func: %s\n", strstr(test, pattern));
	printf("res of my function: %s\n", ft_strstr(test, pattern));
}
*/
