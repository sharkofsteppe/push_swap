/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thirdstage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:09:22 by gesperan          #+#    #+#             */
/*   Updated: 2021/05/28 12:21:13 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	chunks_creation(t_p *p)
{
	int	i;
	int	j;

	p->q = p->len / p->chunk_size;
	if ((p->len - p->chunk_size * p->q) != 0)
		p->q += 1;
	p->chunks = malloc(sizeof(int *) * p->q);
	i = -1;
	while (++i < p->q)
		p->chunks[i] = ft_calloc(sizeof(int), p->chunk_size);
	i = -1;
	while (++i < p->q)
	{
		j = -1;
		while (++j < p->chunk_size)
		{
			if (p->s_len == p->len)
				break ;
			p->chunks[i][j] = p->arr[++p->s_len];
		}
	}
}

void	find_hold_first(int **a, t_p *p)
{
	int	k;
	int	j;

	k = -1;
	while (++k <= p->l_a / 2)
	{
		j = -1;
		while (++j < p->chunk_size)
		{
			if ((*a)[k] == p->chunks[p->i][j])
			{
				p->h_f = k;
				j = p->chunk_size;
			}
		}
		if (p->h_f != -1)
			return ;
	}
}

void	find_hold_second(int **a, t_p *p)
{
	int	k;
	int	j;

	k = p->l_a;
	while (--k > p->l_a / 2)
	{
		j = -1;
		while (++j <p->chunk_size)
		{
			if ((*a)[k] == p->chunks[p->i][j])
			{
				p->h_s = k;
				j = p->chunk_size;
			}
		}
		if (p->h_s != -1)
			return ;
	}
}

void	correct_spot(int **a, int **b, t_p *p)
{
	if (p->h_f == -1)
	{
		p->cn = p->h_s;
		b_operation_rra(a, b, p);
	}
	if (p->h_s == -1)
	{
		p->cn = p->h_f;
		b_operation_ra(a, b, p);
	}
	if (p->h_f != -1 && p->h_s != -1)
	{
		if (p->h_f + 0 < p->l_a - p->h_s)
		{
			p->cn = p->h_f;
			b_operation_ra(a, b, p);
		}
		else
		{
			p->cn = p->h_s;
			b_operation_rra(a, b, p);
		}
	}
}

void	third_stage(int **a, int **b, t_p *p)
{
	chunks_creation(p);
	p->count = 0;
	while (1)
	{
		find_hold_first(a, p);
		find_hold_second(a, p);
		correct_spot(a, b, p);
		p->h_s = -1;
		p->h_f = -1;
		if (p->count == p->chunk_size)
		{
			p->i++;
			p->count = 0;
		}
		if (p->omlen == 0)
		{
			fill_stack_a(a, b, p);
			return ;
		}
	}
}
