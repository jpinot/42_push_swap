/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:01:14 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/21 19:44:15 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static t_stack	*ft_b_s(t_stack *a, t_ret *res, int p)
{
	if (ft_check_side(a, p) == 1)
		while (a->bgn->pos != p)
			ft_ra(a, res);
	else
		while (a->bgn->pos != p)
			a = ft_rra(a, res);
	return (a);
}

int		ft_chk_sort(t_stack *a)
{
	t_num *n;

	n = a->bgn;
	while(n->next)
	{
		if(n->num > n->next->num)
			return (1);
		n = n->next;
	}
	return (0);
}

t_ret			*ft_bubble_one(t_num *bgn)
{
	int		p;
	t_ret	*res;
	t_stack	*a;

	res = ft_ret_new(2);
	if (!(a = ft_stacknew(bgn)))
		return (NULL);
	a = ft_stacknew(bgn);
	p = 0;
	while (p != a->l - 1 && ft_chk_sort(a) != 0)
	{
		ft_b_s(a, res, p);
		if (ft_chk_sort(a) != 0)
			ft_pb(a, a->s_b, res);
		p++;
	}
	while (a->s_b->bgn)
	{
		ft_pa(a, a->s_b, res);
		p--;
	}
	ft_del_stack(&a);
	return (res);
}
