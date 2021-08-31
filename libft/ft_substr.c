/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:42:59 by gesperan          #+#    #+#             */
/*   Updated: 2021/05/28 13:37:24 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	forstart;
	size_t	min;
	char	*substring;

	i = 0;
	forstart = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substring = ft_calloc(sizeof(char), 1);
		return (substring);
	}
	min = ft_strlen(s) - start;
	if (min < len)
		len = min;
	substring = (char *)ft_calloc(sizeof(char), (len + 1));
	while (i < start)
		i++;
	while (forstart < len)
		substring[forstart++] = s[i++];
	return (substring);
}
