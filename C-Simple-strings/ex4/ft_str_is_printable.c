/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:25:15 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/02 14:46:54 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}

/*
int	main()
{
	char *str1 = "ab@!";
	char *str2 = "21ab%";
	char *str3 = "ABC132";
	char *str4 = "␠";
	char *str5 = "";
	printf("test string: %s, res: %d\n", str1, ft_str_is_printable(str1));
	printf("test string: %s, res: %d\n", str2, ft_str_is_printable(str2));
	printf("test string: %s, res: %d\n", str3, ft_str_is_printable(str3));
	printf("test string: %s, res: %d\n", str4, ft_str_is_printable(str4));
	printf("test string: %s, res: %d\n", str5, ft_str_is_printable(str5));
}
*/
