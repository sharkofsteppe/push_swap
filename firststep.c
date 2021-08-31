/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firststep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gesperan <gesperan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:33:16 by gesperan          #+#    #+#             */
/*   Updated: 2021/05/28 16:40:40 by gesperan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	quickest(int **a, int **b, t_p *p)
{
	if (!(already_sorted(a, p)))
		return ;
	if (p->len <= 3)
		forthree(a, p);
	if (p->len <= 5 && p->len > 3)
		forfive(a, b, p);
	if (p->len > 5)
	{
		if (p->len <= 100)
			p->chunk_size = 20;
		if (p->len >= 500)
			p->chunk_size = 46;
		third_stage(a, b, p);
	}
}

t_p	*init_ptr(int argc)
{
	t_p	*ptr;

	ptr = ft_calloc(sizeof(t_p), 1);
	ptr->len = argc - 1;
	ptr->s_len = -1;
	ptr->omlen = ptr->len;
	ptr->chunk_size = 0;
	ptr->i = 0;
	ptr->q = 0;
	ptr->h_f = -1;
	ptr->h_s = -1;
	ptr->p = 0;
	ptr->s = 0;
	ptr->l_a = argc - 1;
	ptr->l_b = 0;
	ptr->counter = 0;
	ptr->index = 0;
	ptr->flag = 0;
	ptr->arr = ft_calloc(sizeof(int), ptr->len);
	return (ptr);
}

char	**handle_argv(char **str, t_p *p)
{
	char	**argv;

	argv = ft_split(str[1], ' ');
	p->len = size_arr(argv);
	p->omlen = p->len;
	p->l_a = p->len;
	return (argv);
}

void	elser(char **argv, t_p *p, int **a, int **b)
{
	int	i;

	i = -1;
	previous_check(p->len + 1, argv);
	(*a) = ft_calloc(sizeof(int), p->len);
	(*b) = ft_calloc(sizeof(int), p->len);
	i = -1;
	while (++i < p->len)
		(*a)[i] = ft_atoi(argv[i + 1]);
}

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	int		i;
	char	**argw;
	t_p		*p;

	p = init_ptr(argc);
	if (argc == 2)
	{
		argw = handle_argv(argv, p);
		previous_checkk(p->len, argw);
		a = ft_calloc(sizeof(int), p->len);
		b = ft_calloc(sizeof(int), p->len);
		i = -1;
		while (++i < p->len)
			a[i] = ft_atoi(argw[i]);
	}
	else
		elser(argv, p, &a, &b);
	primary_sort(a, 0, p->len - 1, p);
	quickest(&a, &b, p);
	return (0);
}
