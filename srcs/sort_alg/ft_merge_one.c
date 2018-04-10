/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 12:07:08 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 18:38:56 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

t_ret	*ft_merge_one(t_num *bgn)
{
	int		g;
	int		p;
	t_ret	*ret;
	t_stack	*a;

	ret = ft_ret_new(3);
	a = ft_stacknew(bgn);
	p = ft_merge_a_bgn(a, ret, a->l - 1);
	while (a->s_b->bgn)
	{
		if (a->bgn && a->s_b->bgn)
			p = ft_merge_b(a, ret, p);
		if (a->bgn && a->s_b->bgn)
			p = ft_merge_a(a, ret, p);
	}
	ft_del_stack(&a);
	return (ret);
}
