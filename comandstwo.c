/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandstwo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:13:56 by gesperan          #+#    #+#             */
/*   Updated: 2021/05/28 14:15:49 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	sb(int **b, t_p *p)
{
	int	tmp;

	tmp = (*b)[0];
	(*b)[0] = (*b)[1];
	(*b)[1] = tmp;
	ft_putstr_fd("sb\n", 1);
	p->counter++;
}

void	pa(int **a, int **b, t_p *p)
{
	int	i;

	i = p->len;
	while (--i > 0)
		(*a)[i] = (*a)[i - 1];
	(*a)[0] = (*b)[0];
	i = -1;
	while (++i < p->l_b)
		(*b)[i] = (*b)[i + 1];
	(*b)[p->l_b - 1] = 0;
	p->l_b = p->l_b - 1;
	p->l_a = p->l_a + 1;
	ft_putstr_fd("pa\n", 1);
	p->counter++;
}

void	pb(int **a, int **b, t_p *p)
{
	int	i;

	i = p->l_b + 1;
	while (--i > 0)
		(*b)[i] = (*b)[i - 1];
	(*b)[0] = (*a)[0];
	i = -1;
	while (++i < p->len - 1)
		(*a)[i] = (*a)[i + 1];
	(*a)[p->len - 1] = 0;
	p->l_a = p->l_a - 1;
	p->l_b = p->l_b + 1;
	ft_putstr_fd("pb\n", 1);
	p->counter++;
}

void	rrr(int **a, int **b, t_p *p)
{
	int	tmp;
	int	i;

	tmp = (*a)[p->l_a - 1];
	i = p->l_a;
	while (--i > 0)
		(*a)[i] = (*a)[i - 1];
	(*a)[0] = tmp;
	tmp = (*b)[p->l_b - 1];
	i = p->l_b;
	while (--i > 0)
		(*b)[i] = (*b)[i - 1];
	(*b)[0] = tmp;
	ft_putstr_fd("rrr\n", 1);
	p->counter++;
}
