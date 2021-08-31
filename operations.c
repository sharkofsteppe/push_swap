/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:11:33 by gesperan          #+#    #+#             */
/*   Updated: 2021/05/28 13:53:36 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	rra_subs(int **a, int **b, t_p *p)
{
	while (p->cn < p->l_a)
	{
		rra(a, p);
		p->cn++;
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

void	rra_big(int **a, int **b, t_p *p)
{
	while (p->index < p->l_b && p->cn < p->l_a)
	{
		rrr(a, b, p);
		p->cn++;
		p->index++;
	}
	while (p->cn < p->l_a)
	{
		rra(a, p);
		p->cn++;
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

void	b_operation_rra(int **a, int **b, t_p *p)
{
	find_index(a, b, p);
	if (p->front <= p->back)
		rra_subs(a, b, p);
	if (p->front > p->back)
		rra_big(a, b, p);
	if (p->flag == 1)
		sb(b, p);
}

int	find_min(int *arr, t_p *p)
{
	int	i;
	int	min;
	int	val;

	i = 0;
	val = arr[i];
	while (i < p->l_b)
	{
		if (val > arr[i])
			val = arr[i];
		i++;
	}
	i = 0;
	while (arr[i] != val)
		i++;
	min = i;
	return (min);
}

int	find_position(int *diff, t_p *p)
{
	int	i;
	int	*duple;
	int	min;

	i = -1;
	duple = ft_calloc(sizeof(int), p->l_b);
	while (++i < p->l_b)
	{
		duple[i] = diff[i];
		if (duple[i] < 0)
			duple[i] *= -1;
	}
	min = find_min(duple, p);
	free(duple);
	return (min);
}
