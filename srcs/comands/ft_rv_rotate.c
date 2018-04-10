/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rv_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:50:53 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 16:51:31 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

t_stack		*ft_rra(t_stack *a, t_ret *ret)
{
	t_num	*tmp;
	char	*del;

	tmp = a->end->prev;
	a->end->next = a->bgn;
	a->end->prev = NULL;
	a->bgn->prev = a->end;
	a->bgn = a->end;
	a->end = tmp;
	a->end->next = NULL;
	del = ret->tp;
	ret->tp = ft_strjoin(ret->tp, " rra");
	ret->mov += 1;
	ft_strdel(&del);
	return (a);
}

t_stack		*ft_rrb(t_stack *b, t_ret *ret)
{
	t_num	*tmp;
	char	*del;

	tmp = b->end->prev;
	b->end->next = b->bgn;
	b->end->prev = NULL;
	b->bgn->prev = b->end;
	b->bgn = b->end;
	b->end = tmp;
	b->end->next = NULL;
	del = ret->tp;
	ret->tp = ft_strjoin(ret->tp, " rrb");
	ret->mov += 1;
	ft_strdel(&del);
	return (b);
}
