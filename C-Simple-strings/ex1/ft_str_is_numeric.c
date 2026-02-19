/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:47:53 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/02 16:50:28 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

/*
int	main()
{
	char *str1 = "98259791";
	char *str2 = "abc";
	char *str3 = "42ab";
	char *str4 = "4 2";
	char *str5 = "";
	printf("test string: %s, res: %d\n", str1, ft_str_is_numeric(str1));
	printf("test string: %s, res: %d\n", str2, ft_str_is_numeric(str2));
	printf("test string: %s, res: %d\n", str3, ft_str_is_numeric(str3));
	printf("test string: %s, res: %d\n", str4, ft_str_is_numeric(str4));
	printf("test string: %s, res: %d\n", str5, ft_str_is_numeric(str5));
}
*/
