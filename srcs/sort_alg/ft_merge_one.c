/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 12:07:08 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/09 17:36:00 by jpinyot          ###   ########.fr       */
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

int	ft_is_sort(t_stack *a, int p)
{
	t_num	*tmp;
	int		cnt;

	tmp = a->bgn;
	cnt = 0;
	if (p == a->l -1)
	{
		while (tmp->next)
		{
			if (tmp->pos != (tmp->next->pos - 1))
				return (0);
			if (tmp->pos == p || tmp->next->pos == p)
				cnt++;
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp->pos != a->l - 1)
		{
			if (tmp->pos != (tmp->next->pos - 1))
				return (0);
			if (tmp->pos == p || tmp->next->pos == p)
				cnt++;
			tmp = tmp->next;
		}
	}
	if (cnt > 0)
		return (1);
	return (0);
}

static int	ft_merge_a_bgn(t_stack *a, t_ret *ret, int p)
{
	int pos;
	int tmp;
	int m;
	int i;

	tmp = ft_check_m(a) / 2;
	pos = (p + 1) - tmp;
	i = a->bgn->m + 1;
	m = a->end->m;
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
			if (a->s_b->bgn->pos < pos)
				ft_rb(a->s_b, ret);
			else
			{
				ft_pa(a, a->s_b, ret);
				i--;
			}
		}
		if (a->s_b->end->m != 0)
			while (a->s_b->end->m == m)
				ft_rrb(a->s_b, ret);
	}
	return (p);
}

t_ret	*ft_merge_one(t_num *bgn)
{
	int		g;
	int		p;
	t_ret	*ret;
	t_stack	*a;

	ret = ft_ret_new(3);
	a = ft_stacknew(bgn);
	p = ft_merge_a_bgn(a,ret, a->l - 1);
	while (a->s_b->bgn)
	{
		if(a->bgn && a->s_b->bgn)
			p = ft_merge_b(a, ret, p);
		if(a->bgn && a->s_b->bgn)
			p = ft_merge_a(a, ret, p);
	}
	return (ret);
}
