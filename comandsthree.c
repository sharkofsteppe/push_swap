/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandsthree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:16:58 by gesperan          #+#    #+#             */
/*   Updated: 2021/05/27 18:18:36 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	rra(int **stack, t_p *p)
{
	int	tmp;
	int	i;

	tmp = (*stack)[p->l_a - 1];
	i = p->l_a;
	while (--i > 0)
		(*stack)[i] = (*stack)[i - 1];
	(*stack)[0] = tmp;
	ft_putstr_fd("rra\n", 1);
	p->counter++;
}

void	rrb(int **stack, t_p *p)
{
	int	tmp;
	int	i;

	tmp = (*stack)[p->l_b - 1];
	i = p->l_b;
	while (--i > 0)
		(*stack)[i] = (*stack)[i - 1];
	(*stack)[0] = tmp;
	ft_putstr_fd("rrb\n", 1);
	p->counter++;
}

void	needtodo(t_p *p, int *left, int *right, int pivot)
{
	while (p->arr[*right] >= pivot && *left < *right)
		(*right)--;
	if (*left != *right)
	{
		p->arr[*left] = p->arr[*right];
		(*left)++;
	}
	while (p->arr[*left] <= pivot && *left < *right)
		(*left)++;
	if (*left != *right)
	{
		p->arr[*right] = p->arr[*left];
		(*right)--;
	}
}

void	primary_sort(int *arr, int left, int right, t_p *p)
{
	int	pivot;
	int	l_hold;
	int	r_hold;
	int	i;

	pivot = arr[left];
	l_hold = left;
	r_hold = right;
	i = -1;
	while (++i < p->len)
		p->arr[i] = arr[i];
	while (left < right)
		needtodo(p, &left, &right, pivot);
	p->arr[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		primary_sort(p->arr, left, pivot - 1, p);
	if (right > pivot)
		primary_sort(p->arr, pivot + 1, right, p);
}
