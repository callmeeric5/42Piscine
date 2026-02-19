/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:14:06 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/16 11:34:43 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	is_first_letter;

	i = 0;
	is_first_letter = 1;
	ft_strlowcase(str);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' && is_first_letter == 1)
			str[i] -= 32;
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
			is_first_letter = 0;
		else
			is_first_letter = 1;
		i++;
	}
	return (str);
}

int	main()
{
	char str1[] = "jO@69&#x27;cK-7#";
	char str2[] = "how are you doing";
	char str3[] = "42words";
	char str4[] =  "forty-two";
	char str5[] = "hello, how are you doing? 42words forty-two; fifty+and+one";

	printf("res: %s\n", ft_strcapitalize(str1));
	printf("res: %s\n", ft_strcapitalize(str2));
	printf("res: %s\n", ft_strcapitalize(str3));
	printf("res: %s\n", ft_strcapitalize(str4));
	printf("res: %s\n", ft_strcapitalize(str5));
}
