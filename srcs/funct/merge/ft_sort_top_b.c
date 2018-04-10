/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_top_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:39:31 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 17:50:29 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static void		ft_first_secod(t_stack *a, t_stack *b, t_ret *ret, int p)
{
	if (b->bgn->pos == p)
		ft_pa(a, b, ret);
	else if (b->bgn->next->pos == p)
	{
		ft_sb(b, ret);
		ft_pa(a, b, ret);
	}
}

static t_stack	*ft_sort_top_three(t_stack *a, t_stack *b, t_ret *ret, int pos)
{
	int p;

	p = pos;
	while (p > pos - 3 && a->s_b != NULL)
	{
		if (b->bgn->pos == p || b->bgn->next->pos == p)
			ft_first_secod(a, b, ret, p);
		else
		{
			if (b->bgn->next->pos == p - 1)
				ft_sb(b, ret);
			if (b->bgn->pos == p - 1)
			{
				ft_pa(a, b, ret);
				ft_sb(b, ret);
				ft_pa(a, b, ret);
				ft_sa(a, ret);
				p -= 1;
			}
		}
		p -= 1;
	}
	return (a);
}

t_stack			*ft_sort_top_b(t_stack *a, t_stack *b, t_ret *ret, int pos)
{
	int m;

	m = ft_check_m(b);
	if (m == 1)
		ft_pa(a, b, ret);
	else if (m == 2)
	{
		if (b->bgn->pos != pos)
			ft_sb(b, ret);
		ft_pa(a, b, ret);
		ft_pa(a, b, ret);
	}
	else
		return (ft_sort_top_three(a, b, ret, pos));
	return (a);
}
