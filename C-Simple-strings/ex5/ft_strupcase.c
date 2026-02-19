/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:31:48 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/01 19:09:27 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

/*
int	main()
{
	char str1[] = "abcde";
	char str2[] = "ABCDE";
	char str3[] = "abc132";
	char str4[] =  "  ab";
	char str5[] = "";

	printf("test string: %s, res: %s\n", str1, ft_strupcase(str1));
	printf("test string: %s, res: %s\n", str2, ft_strupcase(str2));
	printf("test string: %s, res: %s\n", str3, ft_strupcase(str3));
	printf("test string: %s, res: %s\n", str4, ft_strupcase(str4));
	printf("test string: %s, res: %s\n", str5, ft_strupcase(str5));
}
*/
