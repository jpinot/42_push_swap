/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:51:39 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/20 17:32:51 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static t_stack	*ft_swap(t_stack *a)
{
	t_num *tmp;

	tmp = a->bgn->next;
	a->bgn->prev = tmp;
	a->bgn->next = tmp->next;
	tmp->next = a->bgn;
	tmp->prev = NULL;
	a->bgn = tmp;
	return (a);
}

t_stack			*ft_ss(t_stack *a, t_ret *ret)
{
	char *del;

	a = ft_swap(a);
	a->s_b = ft_swap(a->s_b);
	del = ret->tp;
	if (!(ret->tp = ft_strjoin(ret->tp, "ss\n")))
		return (NULL);
	ret->mov += 1;
	return (a);
}
