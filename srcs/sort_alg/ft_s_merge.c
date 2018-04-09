/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 12:07:08 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/28 15:33:51 by jpinyot          ###   ########.fr       */
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

static int	ft_merge_a_bgn(t_stack *a, t_ret *ret, int p)
{
	int pos;
	int tmp;
	int m;
	int i;
	int x;

	tmp = ft_check_m(a) / 2;
	pos = (p + 1) - tmp;
	i = a->bgn->m + 1;
	m = a->end->m;
	x = 0;
	while (a->bgn->next != NULL)
	{
		if (ft_is_sort(a, p))
			break;
		if (ft_check_pos(a->bgn, pos))
		{
			i++;
			if (tmp != 1)
				tmp = tmp / 2;
			pos = tmp + pos;
			ft_putchar(' ');
		}
		if (a->bgn->pos == x)
		{
			a->bgn->m = -2;
			ft_pb(a, a->s_b, ret);
			ft_rb(a->s_b, ret);
			x++;
		}

		if (a->bgn->pos <= pos)
		{
			a->bgn->m = i;
			ft_pb(a, a->s_b, ret);
		}
		else
			ft_ra(a, ret);
	}
	return (a->bgn->pos - 1);
}


static int	ft_merge_a(t_stack *a, t_ret *ret, int p)
{
	int pos;
	int tmp;
	int i;
	int cnt;

	cnt = 0;
	tmp = (ft_check_m(a) / 2);
	if (ft_check_m(a) < 4 && !(ft_is_sort(a, p)))
	{
		a = ft_sort_top_a(a, ret, p);
		return (a->bgn->pos - 1);
	}
	pos = (p + 1) - tmp;
	i = a->s_b->bgn->m + 1;
	ft_putnbr(pos);
	while (a->bgn->next != NULL)
	{
		if (ft_is_sort(a, p))
			break;
		if (ft_non_minor_pos(a, pos))
		{
			if (a->end->m != -1)
				while(a->end->m != -1)
					ft_rra(a, ret);
			return (ft_merge_a(a, ret, p));
		}
		if (a->bgn->pos == a->s_b->end->pos + 1)
		{
			a->bgn->m = -2;
			ft_pb(a, a->s_b, ret);
			ft_rb(a->s_b, ret);
		}
		if (a->bgn->pos >= pos)
			ft_ra(a, ret);
		else
		{
			a->bgn->m = i;
			ft_pb(a, a->s_b, ret);
			cnt++;
		}
	}
	a->bgn->m = -1;
	if (a->end->m != -1)
	{
		while(a->end->m != -1)
			ft_rra(a, ret);
		return (ft_merge_a(a, ret, p - 1));
	}
	return (a->bgn->pos - 1);
}

static int	ft_merge_b(t_stack *a, t_ret *ret, int p)
{
	int pos;
	int m;
	int i;

	m = a->s_b->bgn->m;
	if ((i = (ft_check_m(a->s_b))) < 4)
	{
		a = ft_sort_top_b(a, a->s_b, ret, p);
		p = a->bgn->pos;
	}
	else
	{
		pos = (p + 1) - (i / 2);
		i = (i / 2);
		while (!(ft_non_major_pos(a->s_b, pos)))
		{
			if (a->s_b->bgn->m == -2 && a->s_b->bgn->pos != 0)
				ft_rrb(a->s_b, ret);
			if (a->s_b->bgn->m == -2)
				ft_pa(a, a->s_b, ret);
			else if (a->s_b->bgn->pos < pos)
				ft_rb(a->s_b, ret);
			else
			{
				ft_pa(a, a->s_b, ret);
				i--;
			}
		}
		if (a->s_b->end->m != -2)
			while (a->s_b->end->m != -2)
				ft_rrb(a->s_b, ret);
	}
	return (p);
}

t_ret	*ft_s_merge(t_num *bgn)
{
	int		g;
	int		p;
	t_ret	*ret;
	t_stack	*a;

	ret = ft_ret_new(3);
	a = ft_stacknew(bgn);
	p = ft_merge_a_bgn(a,ret, a->l - 1);
//	p = ft_merge_b(a, ret, p);
//	p = ft_merge_a(a, ret, p);
//	p = ft_merge_b(a, ret, p);

	int i = 1;
	while (a->s_b->bgn->m != -2)
	{
//		ft_putnbr(i);
//		write(1, " ", 1);
		i++;
		if(a->bgn && a->s_b->bgn)
			p = ft_merge_b(a, ret, p);
		if(a->bgn && a->s_b->bgn)
			p = ft_merge_a(a, ret, p);
	}
//	p = ft_merge_b(a, ret, p);
//	write(1, "&", 1);
//	p = ft_merge_a(a, ret, p);

//	ft_putstr(ret->tp);
//	write(1, "\n", 1);
//	ft_putnbr(ret->mov);
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
		write(1, " ", 1);
		ft_putnbr(a->s_b->bgn->m);
		a->s_b->bgn = a->s_b->bgn->next;
	}
		write(1, "\n", 1);
		write(1, "-----------------------------", 10);
		write(1, "\n", 1);
	while (a->bgn)
	{
		write(1, "\n", 1);
		ft_putnbr(a->bgn->num);
		write(1, " ", 1);
		ft_putnbr(a->bgn->pos);
		write(1, " ", 1);
		ft_putnbr(a->bgn->m);
		a->bgn = a->bgn->next;
	}
//	write(1, "\n", 1);
//	ft_putstr(res.tp);
	return (ret);
}
