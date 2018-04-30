/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:08:24 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/29 09:18:09 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static int	ft_r_b_n(t_stack *a, t_ret *ret)
{
	if (a->end->m != -1)
	{
		while (a->end->m != -1)
		{
			if (!(ft_rra(a, ret)))
				return (-2);
		}
		return (-10);
	}
	return (a->bgn->pos - 1);
}

static int	ft_pb_nd_ra(t_stack *a, t_ret *ret, int pos, int i)
{
	if (a->bgn->pos >= pos)
	{
		if (!(ft_ra(a, ret)))
			return (-1);
	}
	else
	{
		a->bgn->m = i;
		if (!(ft_pb(a, a->s_b, ret)))
			return (-1);
	}
	return (1);
}

static int	ft_three_arg(t_stack *a, t_ret *ret, int p)
{
	if (ft_check_m(a) < 4 && !(ft_is_sort(a, p)))
	{
		if (!(a = ft_sort_top_a(a, ret, p)))
			return (-2);
		return (a->bgn->pos - 1);
	}
	return (1);
}

int			ft_merge_a(t_stack *a, t_ret *ret, int p)
{
	int pos;
	int i;

	if ((pos = ft_three_arg(a, ret, p)) == -2)
		return (-2);
	else if (pos != 1)
		return (pos);
	pos = (p + 1) - (ft_check_m(a) / 2);
	i = a->s_b->bgn->m + 1;
	while (a->bgn->next != NULL && !ft_is_sort(a, p))
	{
		if (ft_non_minor_pos(a, pos))
		{
			if (ft_r_b_n(a, ret) == -1)
				return (-2);
			return (ft_merge_a(a, ret, p));
		}
		if (ft_pb_nd_ra(a, ret, pos, i) == -1)
			return (-2);
	}
	a->bgn->m = -1;
	p = a->bgn->pos - 1;
	if ((i = ft_r_b_n(a, ret)) == -10)
		return (ft_merge_a(a, ret, p));
	return (i);
}
