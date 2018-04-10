/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:12:17 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 17:36:00 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	ft_merge_b(t_stack *a, t_ret *ret, int p)
{
	int pos;
	int m;

	m = a->s_b->bgn->m;
	if (ft_check_m(a->s_b) < 4)
	{
		a = ft_sort_top_b(a, a->s_b, ret, p);
		p = a->bgn->pos;
	}
	else
	{
		pos = (p + 1) - (ft_check_m(a->s_b) / 2);
		while (!(ft_non_major_pos(a->s_b, pos)))
		{
			if (a->s_b->bgn->pos < pos)
				ft_rb(a->s_b, ret);
			else
				ft_pa(a, a->s_b, ret);
		}
		if (a->s_b->end->m != 0)
			while (a->s_b->end->m == m)
				ft_rrb(a->s_b, ret);
	}
	return (p);
}
