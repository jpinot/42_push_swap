/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:08:24 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 17:28:20 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static int	ft_r_b_n(t_stack *a, int p, t_ret *ret)
{
	if (a->end->m != -1)
	{
		while (a->end->m != -1)
			ft_rra(a, ret);
		return (1);
	}
	return (0);
}

static void	ft_pb_nd_ra(t_stack *a, t_ret *ret, int pos, int i)
{
	if (a->bgn->pos >= pos)
		ft_ra(a, ret);
	else
	{
		a->bgn->m = i;
		ft_pb(a, a->s_b, ret);
	}
}

int			ft_merge_a(t_stack *a, t_ret *ret, int p)
{
	int pos;
	int i;

	if (ft_check_m(a) < 4 && !(ft_is_sort(a, p)))
	{
		a = ft_sort_top_a(a, ret, p);
		return (a->bgn->pos - 1);
	}
	pos = (p + 1) - (ft_check_m(a) / 2);
	i = a->s_b->bgn->m + 1;
	while (a->bgn->next != NULL)
	{
		if (ft_is_sort(a, p))
			break ;
		if (ft_non_minor_pos(a, pos))
		{
			ft_r_b_n(a, p, ret);
			return (ft_merge_a(a, ret, p));
		}
		ft_pb_nd_ra(a, ret, pos, i);
	}
	a->bgn->m = -1;
	if (ft_r_b_n(a, p, ret))
		return (ft_merge_a(a, ret, p - 1));
	return (a->bgn->pos - 1);
}
