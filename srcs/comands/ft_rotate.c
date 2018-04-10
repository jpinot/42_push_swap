/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:47:49 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 16:48:45 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

t_stack		*ft_ra(t_stack *a, t_ret *ret)
{
	t_num	*tmp;
	char	*del;

	tmp = a->bgn->next;
	a->bgn->next = NULL;
	a->bgn->prev = a->end;
	a->end->next = a->bgn;
	a->end = a->bgn;
	a->bgn = tmp;
	a->bgn->prev = NULL;
	del = ret->tp;
	ret->tp = ft_strjoin(ret->tp, " ra");
	ret->mov += 1;
	ft_strdel(&del);
	return (a);
}

t_stack		*ft_rb(t_stack *b, t_ret *ret)
{
	t_num	*tmp;
	char	*del;

	tmp = b->bgn->next;
	b->bgn->next = NULL;
	b->bgn->prev = b->end;
	b->end->next = b->bgn;
	b->end = b->bgn;
	b->bgn = tmp;
	b->bgn->prev = NULL;
	del = ret->tp;
	ret->tp = ft_strjoin(ret->tp, " rb");
	ret->mov += 1;
	ft_strdel(&del);
	return (b);
}
