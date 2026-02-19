/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:01:37 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/01 18:11:30 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}
/*
int	main()
{
	char *str1 = "abcde";
	char *str2 = "ABCDE";
	char *str3 = "abc132";
	char *str4 = "  ab";
	char *str5 = "";
	printf("test string: %s, res: %d\n", str1, ft_str_is_lowercase(str1));
	printf("test string: %s, res: %d\n", str2, ft_str_is_lowercase(str2));
	printf("test string: %s, res: %d\n", str3, ft_str_is_lowercase(str3));
	printf("test string: %s, res: %d\n", str4, ft_str_is_lowercase(str4));
	printf("test string: %s, res: %d\n", str5, ft_str_is_lowercase(str5));
}
*/
