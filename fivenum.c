/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fivenum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:20:26 by gesperan          #+#    #+#             */
/*   Updated: 2021/05/27 18:21:59 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	lastfive(int **a, int **b, t_p *p)
{
	if ((*b)[0] > (*a)[0] && (*b)[0] > (*a)[1] && (*b)[0] < (*a)[2])
	{
		rra(a, p);
		rra(a, p);
		pa(a, b, p);
		sa(a, p);
		rra(a, p);
	}
}

void	five_f(int **a, int **b, t_p *p)
{
	if ((*b)[0] < (*a)[0])
	{
		pa(a, b, p);
		return ;
	}
	if ((*b)[0] > (*a)[2])
	{
		pa(a, b, p);
		ra(a, p);
		return ;
	}
	if ((*b)[0] > (*a)[0] && (*b)[0] < (*a)[1])
	{
		pa(a, b, p);
		sa(a, p);
		return ;
	}
	lastfive(a, b, p);
}

void	llast_five(int **a, int **b, t_p *p)
{
	if ((*b)[0] > (*a)[0] && (*b)[0] > (*a)[1] && (*b)[0] < (*a)[2])
	{
		ra(a, p);
		pa(a, b, p);
		sa(a, p);
		rra(a, p);
	}
	if ((*b)[0] > (*a)[2] && (*b)[0] < (*a)[3])
	{
		rra(a, p);
		pa(a, b, p);
		ra(a, p);
		ra(a, p);
	}
}

void	five_s(int **a, int **b, t_p *p)
{
	if ((*b)[0] < (*a)[0])
	{
		pa(a, b, p);
		return ;
	}
	if ((*b)[0] > (*a)[3])
	{
		pa(a, b, p);
		ra(a, p);
		return ;
	}
	if ((*b)[0] > (*a)[0] && (*b)[0] < (*a)[1])
	{
		pa(a, b, p);
		sa(a, p);
		return ;
	}
	llast_five(a, b, p);
}

void	forfive(int **a, int **b, t_p *p)
{
	pb(a, b, p);
	if (p->len == 5)
		pb(a, b, p);
	forthree(a, p);
	five_f(a, b, p);
	five_s(a, b, p);
}
