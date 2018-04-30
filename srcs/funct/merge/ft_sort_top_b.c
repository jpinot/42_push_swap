/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_top_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:39:31 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/28 18:44:04 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static int		ft_first_secod(t_stack *a, t_stack *b, t_ret *ret, int p)
{
	if (b->bgn->pos == p)
	{
		if (!ft_pa(a, b, ret))
			return (-1);
	}
	else if (b->bgn->next->pos == p)
		if (!ft_sb(b, ret) || !ft_pa(a, b, ret))
			return (-1);
	return (1);
}

static t_stack	*ft_sort_top_three(t_stack *a, t_stack *b, t_ret *ret, int pos)
{
	int p;

	p = pos;
	while (p > pos - 3 && a->s_b != NULL)
	{
		if (b->bgn->pos == p || b->bgn->next->pos == p)
		{
			if (ft_first_secod(a, b, ret, p) == -1)
				return (NULL);
		}
		else
		{
			if (b->bgn->next->pos == p - 1)
				if (!ft_sb(b, ret))
					return (NULL);
			if (!ft_pa(a, b, ret) || !ft_sb(b, ret)
					|| !ft_pa(a, b, ret) || !ft_sa(a, ret))
				return (NULL);
			p -= 1;
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
	{
		if (!ft_pa(a, b, ret))
			return (NULL);
	}
	else if (m == 2)
	{
		if (b->bgn->pos != pos)
			if (!ft_sb(b, ret))
				return (NULL);
		if (!ft_pa(a, b, ret) || !ft_pa(a, b, ret))
			return (NULL);
	}
	else
		return (ft_sort_top_three(a, b, ret, pos));
	return (a);
}
