/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:18:29 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/23 14:45:49 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int  ft_check_m(t_stack *a)
{
	t_num   *tmp;
	int     i;
	int     ref;

	tmp = a->bgn;
	ref = tmp->m;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->m != ref)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static t_stack	*ft_sort_top_three(t_stack *a, t_stack *b, t_ret ret, int pos)
{
	int m;
	int p;

	m = a->s_b->bgn->m;
	p = pos;
	while (p > pos - 3 && a->s_b != NULL)
	{
		if (b->bgn->pos == p)
			ft_pa(a, b, ret);
		else if (b->bgn->next->pos == p)
		{
			ft_sb(b, ret);
			ft_pa(a, b, ret);
		}
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

t_stack *ft_sort_top(t_stack *a, t_stack *b, t_ret ret, int pos)
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
