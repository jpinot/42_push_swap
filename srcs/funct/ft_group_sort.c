/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:29:22 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/23 14:15:09 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

t_stack	*ft_group_sort(t_stack *a, t_stack *b, t_ret ret)
{
	int g;
	int p;

	g = a->l_g -2;
	p = 2;
	while (g != -1)
	{
		if (b->bgn->p == p)
			ft_pa(a, b, ret);
		else if (b->bgn->next->p == p)
		{
			ft_sb(b, ret);
			ft_pa(a, b, ret);
		}
		else
		{
			if (b->bgn->next->p == p -1)
				ft_sb(b, ret);
			if (b->bgn->p == p - 1)
			{
				ft_pa(a, b, ret);
				ft_sb(b, ret);
				ft_pa(a, b, ret);
				ft_sa(a, ret);
				p -= 1;
			}
		}
		p--;
		if (p == -1)
		{
			g -= 1;
			p = 2;
		}
	}
		return (a);
}
