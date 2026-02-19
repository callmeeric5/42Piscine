/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:28:15 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/04 23:52:46 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	is_partial_word;
	int	is_sep;
	int	count;

	i = 0;
	is_partial_word = 0;
	count = 0;
	while (str[i])
	{
		is_sep = is_separator(str[i], charset);
		if (is_sep)
		{
			is_partial_word = 0;
		}
		else
		{
			if (!is_partial_word)
				count++;
			is_partial_word = 1;
		}
		i++;
	}
	return (count);
}

char	*ft_strdup(char *src, int length)
{
	char	*array;
	int		i;

	array = malloc((length + 1) * sizeof(char));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		array[i] = src[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	**ft_split(char *str, char *charset)
{
	int		word_len;
	char	**res;
	int		i;

	if (!str || !charset)
		return (NULL);
	res = malloc((count_word(str, charset) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (!is_separator(*str, charset))
		{
			word_len = 0;
			while (str[word_len] && !is_separator(str[word_len], charset))
				word_len++;
			res[i++] = ft_strdup(str, word_len);
			str += word_len;
		}
		else
			str++;
	}
	res[i] = NULL;
	return (res);
}

/*
int	main(void)
{
	char	**result;
	int	i;


	result = ft_split("Hello,//Wor::ld;   T\'est", " '/,;:");
	printf("Hello,//Wor::ld; T\'est split by ' /\',;:'\n");
	i = 0;
	while (result[i])
	{
		printf(" '%s'\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
}
*/
