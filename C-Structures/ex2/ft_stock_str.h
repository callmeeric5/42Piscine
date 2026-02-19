/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:48:52 by ziwang            #+#    #+#             */
/*   Updated: 2026/02/07 18:48:53 by ziwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FT_STOCK_STR
# define FT_STOCK_STR
typedef struct s_stock_str
{
	int				size;
	char			*str;
	char			*copy;
}					t_stock_str;

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void				ft_show_tab(struct s_stock_str *par);
#endif
