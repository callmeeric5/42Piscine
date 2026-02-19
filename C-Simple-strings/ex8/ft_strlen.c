/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:20:47 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/01 19:23:11 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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

/*
int	main()
{
	char *str1 = "abcdefghijklmnopqrstuvwxyz";
	char *str2 = "4312432153254";
	char *str3 = "ABC132";
	char *str4 = "  AB";
	char *str5 = "";
	printf("test string: %s, res: %d\n", str1, ft_strlen(str1));
	printf("test string: %s, res: %d\n", str2, ft_strlen(str2));
	printf("test string: %s, res: %d\n", str3, ft_strlen(str3));
	printf("test string: %s, res: %d\n", str4, ft_strlen(str4));
	printf("test string: %s, res: %d\n", str5, ft_strlen(str5));
}
*/
