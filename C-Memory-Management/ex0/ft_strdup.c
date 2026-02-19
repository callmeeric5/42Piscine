/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:05:27 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/04 21:46:27 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
int	ft_str_len(char *str);

char	*ft_strdup(char *src)
{
	char	*array;
	int		length;
	int		i;

	if (!src)
		return (NULL);
	length = ft_str_len(src);
	array = malloc((length + 1) * sizeof(char));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		array[i] = src[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

int	ft_str_len(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

/*
int main()
{
	char str[] = "abc";
	char *duplicate;
	duplicate = ft_strdup(NULL);
	printf("src: %s, duplicate: %s\n", str, duplicate);
}
*/
