/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:01:14 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/28 15:45:18 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static t_stack	*ft_b_s(t_stack *a, t_ret *res, int p)
{
	if (ft_check_side(a, p) == 1)
	{
		while (a->bgn->pos != p)
			if (!(ft_ra(a, res)))
				return (NULL);
	}
	else
	{
		while (a->bgn->pos != p)
			if (!(a = ft_rra(a, res)))
				return (NULL);
	}
	return (a);
}

int				ft_chk_sort(t_stack *a)
{
	t_num *n;

	n = a->bgn;
	while (n->next)
	{
		if (n->num > n->next->num)
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

	if (!(res = ft_ret_new(2)))
		return (NULL);
	if (!(a = ft_stacknew(bgn)))
		return (NULL);
	p = 0;
	while (p != a->l - 1 && ft_chk_sort(a) != 0)
	{
		if (!(ft_b_s(a, res, p)))
			return (NULL);
		if (ft_chk_sort(a) != 0)
			if (!(ft_pb(a, a->s_b, res)))
				return (NULL);
		p++;
	}
	while (a->s_b->bgn)
		if (!(ft_pa(a, a->s_b, res)))
			return (NULL);
	ft_del_stack(&a);
	return (res);
}
