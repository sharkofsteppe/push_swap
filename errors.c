/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:30:17 by gesperan          #+#    #+#             */
/*   Updated: 2021/05/28 12:16:43 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_errich(int a)
{
	if (a == ERR_0)
		return (ps_cub("Error. ANOTHER SYMBOLS\n", 1, ERR_0));
	if (a == ERR_1)
		return (ps_cub("Error. NOT INT\n", 1, ERR_1));
	if (a == ERR_2)
		return (ps_cub("Error. REPEATING SYMBOLS\n", 1, ERR_2));
	if (a == ERR_3)
		return (ps_cub("Error\nUnexpected symbols\n", 1, ERR_3));
	return (0);
}
