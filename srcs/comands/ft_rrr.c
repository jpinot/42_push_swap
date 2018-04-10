/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:50:16 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 16:50:38 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static t_stack	*ft_reverse(t_stack *a)
{
	t_num *tmp;

	tmp = a->end->prev;
	a->end->next = a->bgn;
	a->end->prev = NULL;
	a->bgn->prev = a->end;
	a->bgn = a->end;
	a->end = tmp;
	a->end->next = NULL;
	return (a);
}

t_stack			*ft_rrr(t_stack *a, t_ret *ret)
{
	char	*del;

	a = ft_reverse(a);
	a->s_b = ft_reverse(a->s_b);
	del = ret->tp;
	ret->tp = ft_strjoin(ret->tp, " rrr");
	ret->mov += 1;
	ft_strdel(&del);
	return (a);
}
