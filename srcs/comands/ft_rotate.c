/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:47:49 by jpinyot           #+#    #+#             */
/*   Updated: 2018/05/01 18:46:40 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

t_stack		*ft_ra(t_stack *a, t_ret *ret)
{
	t_num	*tmp;
	char	*del;

	if (a->bgn == NULL || a->bgn->next == NULL)
		return (a);
	tmp = a->bgn->next;
	a->bgn->next = NULL;
	a->bgn->prev = a->end;
	a->end->next = a->bgn;
	a->end = a->bgn;
	a->bgn = tmp;
	a->bgn->prev = NULL;
	del = ret->tp;
	if (!(ret->tp = ft_strjoin(ret->tp, "ra\n")))
		return (NULL);
	ret->mov += 1;
	ft_strdel(&del);
	return (a);
}

t_stack		*ft_rb(t_stack *b, t_ret *ret)
{
	t_num	*tmp;
	char	*del;

	if (b->bgn == NULL || b->bgn->next == NULL)
		return (b);
	tmp = b->bgn->next;
	b->bgn->next = NULL;
	b->bgn->prev = b->end;
	b->end->next = b->bgn;
	b->end = b->bgn;
	b->bgn = tmp;
	b->bgn->prev = NULL;
	del = ret->tp;
	if (!(ret->tp = ft_strjoin(ret->tp, "rb\n")))
		return (NULL);
	ret->mov += 1;
	ft_strdel(&del);
	return (b);
}
