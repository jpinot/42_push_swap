/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:52:15 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 16:53:12 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

t_stack	*ft_sa(t_stack *a, t_ret *ret)
{
	t_num	*tmp;
	char	*d;

	tmp = a->bgn->next;
	a->bgn->prev = tmp;
	a->bgn->next = tmp->next;
	tmp->next = a->bgn;
	tmp->prev = NULL;
	a->bgn = tmp;
	d = ret->tp;
	ret->tp = ft_strjoin(ret->tp, " sa");
	ret->mov += 1;
	ft_strdel(&d);
	return (a);
}

t_stack	*ft_sb(t_stack *b, t_ret *ret)
{
	t_num	*tmp;
	char	*d;

	tmp = b->bgn->next;
	b->bgn->prev = tmp;
	b->bgn->next = tmp->next;
	tmp->next = b->bgn;
	tmp->prev = NULL;
	b->bgn = tmp;
	d = ret->tp;
	ret->tp = ft_strjoin(ret->tp, " sb");
	ret->mov += 1;
	ft_strdel(&d);
	return (b);
}
