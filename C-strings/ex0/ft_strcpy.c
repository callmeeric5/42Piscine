/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 07:30:12 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/05 08:28:05 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src1[] = "apple";
	char	src2[] = "";
	char	dst1[10];
	char	dst2[10];

	printf("original: %s, before copied: %s\n", src1, dst1);
	ft_strcpy(dst1, src1);
	printf("original: %s, before copied: %s\n", src2, dst2);
	ft_strcpy(dst2, src2);
	printf("original: %s, after copied: %s\n", src1, dst1);
	printf("original: %s, after copied: %s\n", src2, dst2);
}
*/
