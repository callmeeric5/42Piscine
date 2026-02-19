/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:10:40 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/02 13:51:57 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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

/*
int	main()
{
	char str1[] = "abcde";
	char str2[] = "ABCDE";
	char str3[] = "ABC132";
	char str4[] =  "  AB";
	char str5[] = "";

	printf("test string: %s, res: %s\n", str1, ft_strlowcase(str1));
	printf("test string: %s, res: %s\n", str2, ft_strlowcase(str2));
	printf("test string: %s, res: %s\n", str3, ft_strlowcase(str3));
	printf("test string: %s, res: %s\n", str4, ft_strlowcase(str4));
	printf("test string: %s, res: %s\n", str5, ft_strlowcase(str5));
}
*/
