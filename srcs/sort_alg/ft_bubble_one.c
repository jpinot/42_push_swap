/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:01:14 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 18:38:36 by jpinyot          ###   ########.fr       */
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
	while (p != a->l - 1)
	{
		ft_b_s(a, res, p);
		ft_pb(a, a->s_b, res);
		p++;
	}
	while (p > 0)
	{
		ft_pa(a, a->s_b, res);
		p--;
	}
	ft_del_stack(&a);
	return (res);
}
