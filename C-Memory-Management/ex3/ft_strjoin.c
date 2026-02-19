/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:00:26 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/05 03:19:38 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
/*
1. Calculate the total length of strs and the seperator;
2. Allocate a continuious for the joined str;
3. Copy each str of strs to the allocated memory,
move the pointer to the end of the str for inserting the seperator;
4. Insert the seperator;
5. Add \0 to the end of the final str;
*/

int		ft_strlen(char *str);
int		ft_fulllen(int size, char **strs, char *sep);
char	*ft_copy(char *src, char *dst);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;
	char	*current;

	if (size == 0)
	{
		res = (char *) malloc(1);
		if (res)
			res[0] = '\0';
		return (res);
	}
	res = (char *) malloc(ft_fulllen(size, strs, sep) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	current = res;
	while (i < size)
	{
		current = ft_copy(strs[i], current);
		if (i < size - 1)
			current = ft_copy(sep, current);
		i++;
	}
	*current = '\0';
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_fulllen(int size, char **strs, char *sep)
{
	int	i;
	int	length;

	i = 0;
	length = 1;
	while (i < size)
	{
		length += ft_strlen(strs[i]);
		i++;
	}
	length += (size - 1) * ft_strlen(sep);
	return (length);
}

char	*ft_copy(char *src, char *dst)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (dst + i);
}

/*
int	main()
{
	char *str1[] = {"hello", "world", "this", "is", "call", "from", "42"};
	char *str2[] = {"Hello", "Foo", "", "Test"};
	char *str3[] = {"","Full","","Stack"};
	char *res;
	res = ft_strjoin(7, str1, ",");
	printf("%s\n", res);
	printf("%s\n", ft_strjoin(1, str1, ""));
}
*/
