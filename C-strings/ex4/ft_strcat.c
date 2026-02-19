/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:10:08 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/05 10:54:20 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
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
	char	dest1[11] = "I eat";
	char	dest2[11] = "I eat";

	ft_strcat(dest2, src2);
	strcat(dest1, src1);
	printf("res of original func: %s\nres of my func: %s\n", dest1, dest2);
}
*/
