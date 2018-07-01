/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:49:04 by jpinyot           #+#    #+#             */
/*   Updated: 2018/05/06 21:42:46 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static t_stack	*ft_rotate(t_stack *a)
{
	t_num *tmp;

	tmp = a->bgn->next;
	a->bgn->next = NULL;
	a->bgn->prev = a->end;
	a->end->next = a->bgn;
	a->end = a->bgn;
	a->bgn = tmp;
	a->bgn->prev = NULL;
	return (a);
}

t_stack			*ft_rr(t_stack *a, t_ret *ret)
{
	char *del;

	if (a->bgn && a->bgn->next)
		a = ft_rotate(a);
	if (a->s_b->bgn && a->s_b->bgn->next)
		a->s_b = ft_rotate(a->s_b);
	del = ret->tp;
	if (!(ret->tp = ft_strjoin(ret->tp, "rr\n")))
		return (NULL);
	ret->mov += 1;
	ft_strdel(&del);
	return (a);
}
