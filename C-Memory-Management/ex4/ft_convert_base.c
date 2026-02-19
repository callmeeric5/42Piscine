/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:28:20 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/10 18:28:29 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
1. Validate the two bases;
2. Convert number from src base to decimal base;
3. Convert decimal base to dst base;
*/
int		is_base_valid(char *base);
int		srcbase_to_decimal(char *str, char *base);
int		get_idx_in_base(char *base, char c);
int		get_base_len(char *base);
char	*decimal_to_dstbase(int num, char *base);
int		count_digits(int num, int base_len);
int		skip_sign(char *str, int *sign);
void	fill_res(char *res, int num, int base_len, char *base);
int		get_num_len(int num, int base_len);

void	fill_res(char *res, int num, int base_len, char *base)
{
	int	i;
	int	idx;
	int	n_len;

	n_len = get_num_len(num, base_len);
	if (num < 0)
		i = n_len;
	else
		i = n_len - 1;
	if (num == 0)
		res[i] = base[0];
	while (num != 0)
	{
		idx = num % base_len;
		if (idx < 0)
			idx = -idx;
		res[i] = base[idx];
		num /= base_len;
		i--;
	}
}

int	srcbase_to_decimal(char *str, char *base)
{
	int	res;
	int	sign;
	int	base_len;
	int	idx;

	res = 0;
	base_len = get_base_len(base);
	str += skip_sign(str, &sign);
	while (*str)
	{
		idx = get_idx_in_base(base, *str);
		if (idx == -1)
			break ;
		res = res * base_len - idx;
		str++;
	}
	if (sign == 1)
		return (-res);
	return (res);
}

char	*decimal_to_dstbase(int num, char *base)
{
	char	*res;
	int		base_len;
	int		total_len;
	int		num_len;

	base_len = get_base_len(base);
	num_len = get_num_len(num, base_len);
	if (num < 0)
		total_len = num_len + 1;
	else
		total_len = num_len;
	res = malloc(sizeof(char) * (total_len + 1));
	if (res == NULL)
		return (NULL);
	res[total_len] = '\0';
	if (num < 0)
		res[0] = '-';
	fill_res(res, num, base_len, base);
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal_num;
	char	*res;

	if (!is_base_valid(base_from) || !is_base_valid(base_to))
		return (NULL);
	decimal_num = srcbase_to_decimal(nbr, base_from);
	res = decimal_to_dstbase(decimal_num, base_to);
	return (res);
}

#include <stdio.h>

int main()
{
	printf("%s\n", ft_convert_base("b 1++--  a-", "abc", "012"));
	printf("%s\n", ft_convert_base("258", "0123456789", "0123456789abcdef"));
	printf("%s\n", ft_convert_base("-2147483648", "0123456789", "01"));
	printf("%s\n", ft_convert_base("42", "0123456789", "poneyvif"));
}

