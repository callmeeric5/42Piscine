/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 10:37:28 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/05 10:54:16 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (j < nb && src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src1[] = "apple";
	char	src2[] = "apple";
	char	dest1[30] = "I eat";
	char	dest2[30] = "I eat";

	ft_strncat(dest2, src2, 20);
	strncat(dest1, src1, 20);
	printf("res of original func: %s\nres of my func: %s\n", dest1, dest2);
}
*/
