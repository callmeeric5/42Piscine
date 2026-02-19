/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:15:18 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/01 17:47:04 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
int	main()
{
	char *str1 = "abcdefg";
	char *str2 = "ABcdeFG";
	char *str3 = "123456";
	char *str4 = "abc defg";
	char *str5 = "abC123";
	char *str6 = "abs*56";
	char *str7 = "";
	printf("test string: %s, res: %d\n", str1, ft_str_is_alpha(str1));
	printf("test string: %s, res: %d\n", str2, ft_str_is_alpha(str2));
	printf("test string: %s, res: %d\n", str3, ft_str_is_alpha(str3));
	printf("test string: %s, res: %d\n", str4, ft_str_is_alpha(str4));
	printf("test string: %s, res: %d\n", str5, ft_str_is_alpha(str5));
	printf("test string: %s, res: %d\n", str6, ft_str_is_alpha(str6));
	printf("test string: %s, res: %d\n", str7, ft_str_is_alpha(str7));
}
*/
