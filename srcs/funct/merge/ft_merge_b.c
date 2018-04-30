/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:12:17 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/28 17:59:38 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static int	ft_while_non_major(t_stack *a, t_ret *ret, int pos)
{
	while (!(ft_non_major_pos(a->s_b, pos)))
	{
		if (a->s_b->bgn->pos < pos)
		{
			if (!(ft_rb(a->s_b, ret)))
				return (-2);
		}
		else
		{
			if (!(ft_pa(a, a->s_b, ret)))
				return (-2);
		}
	}
	return (0);
}

int			ft_merge_b(t_stack *a, t_ret *ret, int p)
{
	int pos;
	int m;

	m = a->s_b->bgn->m;
	if (ft_check_m(a->s_b) < 4)
	{
		if (!(a = ft_sort_top_b(a, a->s_b, ret, p)))
			return (-2);
		p = a->bgn->pos;
	}
	else
	{
		pos = (p + 1) - (ft_check_m(a->s_b) / 2);
		if (ft_while_non_major(a, ret, pos) == -2)
			return (-2);
		if (a->s_b->end->m != 0)
			while (a->s_b->end->m == m)
				if (!(ft_rrb(a->s_b, ret)))
					return (-2);
	}
	return (p);
}
