/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:10:01 by gesperan          #+#    #+#             */
/*   Updated: 2021/05/28 14:15:38 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	sa(int **stack, t_p *p)
{
	int	tmp;

	tmp = (*stack)[0];
	(*stack)[0] = (*stack)[1];
	(*stack)[1] = tmp;
	ft_putstr_fd("sa\n", 1);
	p->counter++;
}

void	ra(int **stack, t_p *p)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = (*stack)[0];
	while (++i < p->l_a - 1)
		(*stack)[i] = (*stack)[i + 1];
	(*stack)[p->l_a - 1] = tmp;
	ft_putstr_fd("ra\n", 1);
	p->counter++;
}

void	rb(int **stack, t_p *p)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = (*stack)[0];
	while (++i < p->l_b)
		(*stack)[i] = (*stack)[i + 1];
	(*stack)[p->l_b - 1] = tmp;
	ft_putstr_fd("rb\n", 1);
	p->counter++;
}

void	rr(int **a, int **b, t_p *p)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = (*a)[0];
	while (++i < p->l_a - 1)
		(*a)[i] = (*a)[i + 1];
	(*a)[p->l_a - 1] = tmp;
	i = -1;
	tmp = (*b)[0];
	while (++i < p->l_b)
		(*b)[i] = (*b)[i + 1];
	(*b)[p->l_b - 1] = tmp;
	ft_putstr_fd("rr\n", 1);
	p->counter++;
}
