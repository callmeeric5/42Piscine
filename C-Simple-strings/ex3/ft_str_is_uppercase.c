/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:15:57 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/01 18:19:49 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
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
	char *str3 = "ABC132";
	char *str4 = "  AB";
	char *str5 = "";
	printf("test string: %s, res: %d\n", str1, ft_str_is_uppercase(str1));
	printf("test string: %s, res: %d\n", str2, ft_str_is_uppercase(str2));
	printf("test string: %s, res: %d\n", str3, ft_str_is_uppercase(str3));
	printf("test string: %s, res: %d\n", str4, ft_str_is_uppercase(str4));
	printf("test string: %s, res: %d\n", str5, ft_str_is_uppercase(str5));
}
*/
