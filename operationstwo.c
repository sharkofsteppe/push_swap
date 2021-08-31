/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationstwo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:13:27 by gesperan          #+#    #+#             */
/*   Updated: 2021/05/28 12:19:40 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	find_index(int **a, int **b, t_p *p)
{
	int	i;
	int	*diff;

	p->flag = 0;
	diff = 0;
	if (p->l_b != 0)
		diff = ft_calloc(sizeof(int), p->l_b);
	if (p->l_b == 0)
		diff = ft_calloc(sizeof(int), 1);
	i = -1;
	while (++i < p->l_b)
		diff[i] = (*a)[p->cn] - (*b)[i];
	p->index = find_position(diff, p);
	p->front = 0 + p->index;
	p->back = p->l_b - p->index;
	i = -1;
	if (diff[p->index] < 0)
		p->flag = 1;
	free(diff);
}

void	ra_small(int **a, int **b, t_p *p)
{
	while (p->cn > 0 && p->index > 0)
	{
		rr(a, b, p);
		p->cn--;
		p->index--;
	}
	while (p->cn > 0)
	{
		ra(a, p);
		p->cn--;
	}
	while (p->index > 0)
	{
		rb(b, p);
		p->index--;
	}
	pb(a, b, p);
	p->omlen--;
	p->count++;
}

void	ra_big(int **a, int **b, t_p *p)
{
	while (p->cn > 0)
	{
		ra(a, p);
		p->cn--;
	}
	while (p->index < p->l_b)
	{
		rrb(b, p);
		p->index++;
	}
	pb(a, b, p);
	p->omlen--;
	p->count++;
}

void	b_operation_ra(int **a, int **b, t_p *p)
{
	find_index(a, b, p);
	if (p->front <= p->back)
		ra_small(a, b, p);
	if (p->front > p->back)
		ra_big(a, b, p);
	if (p->flag == 1)
		sb(b, p);
}

void	fill_stack_a(int **a, int **b, t_p *p)
{
	p->index = find_min(*b, p);
	p->front = 0 + p->index;
	p->back = p->l_b - p->index;
	if (p->front <= p->back)
	{
		while (p->index > 1)
		{
			rb(b, p);
			p->index--;
		}
	}
	else
	{
		while (p->index < p->l_b - 1)
		{
			rrb(b, p);
			p->index++;
		}
	}
	while (p->l_b != 0)
		pa(a, b, p);
}
