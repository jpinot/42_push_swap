/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_top_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:38:45 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/28 18:30:25 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static t_stack	*ft_sort_top_three(t_stack *a, t_ret *ret, int p)
{
	if (a->bgn->pos == p)
	{
		if (!ft_sa(a, ret) || !ft_ra(a, ret)
				|| !ft_sa(a, ret) || !ft_rra(a, ret))
			return (NULL);
		if (a->bgn->pos > a->bgn->next->pos)
			if (!(ft_sa(a, ret)))
				return (NULL);
	}
	else if (a->bgn->next->pos == p)
	{
		if (!ft_ra(a, ret) || !ft_sa(a, ret) || !ft_rra(a, ret))
			return (NULL);
		if (a->bgn->pos > a->bgn->next->pos)
			if (!(ft_sa(a, ret)))
				return (NULL);
	}
	else
	{
		if (a->bgn->pos > a->bgn->next->pos)
			if (!(ft_sa(a, ret)))
				return (NULL);
	}
	return (a);
}

t_stack			*ft_sort_top_a(t_stack *a, t_ret *ret, int pos)
{
	int m;

	m = ft_check_m(a);
	if (m == 1)
		return (a);
	else if (m == 2)
	{
		if (a->bgn->pos > a->bgn->next->pos)
			if (!(ft_sa(a, ret)))
				return (NULL);
	}
	else
	{
		if (!(a = ft_sort_top_three(a, ret, pos)))
			return (NULL);
	}
	a->bgn->m = -1;
	return (a);
}
