/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:18:56 by gesperan          #+#    #+#             */
/*   Updated: 2021/05/28 16:34:05 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	already_sorted(int **a, t_p *p)
{
	int	i;

	i = -1;
	while (++i < p->len)
	{
		if ((*a)[i] != p->arr[i])
			return (1);
	}
	return (0);
}

void	num_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		if (!ft_isdigit(argv[i][j]))
			exit(ft_errich(ERR_0));
		while (ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j])
			exit(ft_errich(ERR_0));
		i++;
	}
}

void	doubles_check(long int *arr, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (arr[i] == arr[j])
				exit(ft_errich(ERR_2));
			j++;
		}
		i++;
	}
}

void	previous_check(int argc, char **argv)
{
	int			res;
	int			i;
	int			j;
	long int	*arr;

	arr = ft_calloc(sizeof(long int), argc - 1);
	res = 0;
	i = 1;
	j = 0;
	num_check(argc, argv);
	while (i < argc)
	{
		arr[j] = ft_atoi(argv[i]);
		if (arr[j] < -2147483647 || arr[j] > 2147483647)
			exit(ft_errich(ERR_1));
		j++;
		i++;
	}
	i = -1;
	doubles_check(arr, argc);
	free(arr);
}

void	forthree(int **stack, t_p *p)
{
	if (p->len == 2 && (*stack)[0] > (*stack)[1])
		sa(stack, p);
	if ((*stack)[0] > (*stack)[1] && (*stack)[1] < (*stack)[2] &&
		(*stack)[2] > (*stack)[0])
		sa(stack, p);
	if ((*stack)[0] < (*stack)[1] && (*stack)[1] > (*stack)[2] &&
		(*stack)[2] > (*stack)[0])
		sa(stack, p);
	if ((*stack)[0] > (*stack)[1] && (*stack)[1] > (*stack)[2] &&
		(*stack)[2] < (*stack)[0])
		sa(stack, p);
	if ((*stack)[0] < (*stack)[1] && (*stack)[1] > (*stack)[2] &&
		(*stack)[2] < (*stack)[0])
		rra(stack, p);
	if ((*stack)[0] > (*stack)[1] && (*stack)[1] < (*stack)[2] &&
		(*stack)[2] < (*stack)[0])
		ra(stack, p);
}
