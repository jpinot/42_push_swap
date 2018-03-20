/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 12:07:08 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/20 21:10:20 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static int ft_check_pos(t_num *a, int p)
{
	t_num *tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->pos <= p)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
static int	ft_is_sort(t_stack *a, int p)
{
	t_num	*tmp;
	int		cnt;

	tmp = a->bgn;
	cnt = 0;
	while (tmp->next)
	{
		if (tmp->pos != (tmp->next->pos - 1))
			return (0);
		if (tmp->pos == p || tmp->next->pos == p)
			cnt++;
		tmp = tmp->next;
	}
	if (cnt > 0)
		return (1);
	return (0);
}

static int	ft_first_sort(t_stack *a, t_ret ret, int p)
{
	int pos;
	int tmp;

	pos = ((a->l - 1) / 2);
	tmp = pos / 2;
	while (a->bgn->next != NULL)
	{
		if (ft_is_sort(a, p))
			return (tmp * 2);
		if (ft_check_pos(a->bgn, pos))
		{
			pos = tmp + pos;
			if (tmp != 1)
				tmp = tmp / 2;
		}
		if (a->bgn->pos <= pos)
		{
			write(1, "(", 1);
			ft_putnbr(pos);
			write(1, ")", 1);
			ft_pb(a, a->s_b, ret);
			write(1, "*", 1);
		}
		else
			ft_ra(a, ret);
	}
	return (tmp * 2);
}

t_ret	ft_merge_one(t_num *bgn)
{
	int		g;
	int		p;
	t_ret	ret;
	t_stack	*a;

	ret.mov = 0;
	ret.tp = (char *)malloc(sizeof(char) * 5);
	ret.tp = ft_strcpy(ret.tp, "str:");
	a = ft_stacknew(bgn);
	p = a->l - 1;
	g = ft_first_sort(a,ret, p);
	ft_putnbr(g);
//	while (a->s_b)
//	{
//	ft_merge_a(a, a->s_b, ret);
//	ft_merge_b(a, a->s_b, ret);
//
//	}
//	a = ft_sa(a, res);
//	write(1, "$", 1);
//	ft_group_sort(a, a->s_b, res);
//	while (p < a->l - 1)
//	{
//		ft_pa(a, a->s_b, res);
//		p++;
//	}
	while (a->s_b->bgn)
	{
		write(1, "\n", 1);
		ft_putnbr(a->s_b->bgn->num);
		write(1, " ", 1);
		ft_putnbr(a->s_b->bgn->pos);
		a->s_b->bgn = a->s_b->bgn->next;
	}
		write(1, "\n", 1);
		write(1, "----------", 10);
		write(1, "\n", 1);
	while (a->bgn)
	{
		write(1, "\n", 1);
		ft_putnbr(a->bgn->num);
		write(1, " ", 1);
		ft_putnbr(a->bgn->pos);
		a->bgn = a->bgn->next;
	}
//	write(1, "\n", 1);
//	ft_putstr(res.tp);
	return (ret);
}
