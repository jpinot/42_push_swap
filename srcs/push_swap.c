/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:51:17 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/29 11:37:30 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static t_num	*ft_copynum(t_num *n)
{
	t_num *num;
	t_num *bgn;
	t_num *s;

	s = n;
	if ((num = ft_lstnew_num(s->num, NULL)) == NULL)
		return (NULL);
	bgn = num;
	while (s->next)
	{
		if ((num->next = ft_lstnew_num(s->next->num, num)) == NULL)
			return (NULL);
		num = num->next;
		s = s->next;
	}
	return (bgn);
}

static void		ft_print_res(t_ret *op)
{
	if (op->mov <= op->next->mov && op->mov <= op->next->next->mov)
		ft_putstr(&(op->tp[4]));
	else if (op->mov > op->next->mov && op->next->mov <= op->next->next->mov)
		ft_putstr(&(op->next->tp[4]));
	else if (op->mov > op->next->next->mov &&
			op->next->mov > op->next->next->mov)
		ft_putstr(&(op->next->next->tp[4]));
}

int				push_swap(t_num *bgn)
{
	t_ret	*op;
	t_num	*n2;
	t_num	*n3;

	if (!(n2 = ft_copynum(bgn)))
		return (-1);
	if (!(n3 = ft_copynum(bgn)))
		return (-1);
	if (!(op = ft_bubble_one(bgn)))
		return (-1);
	if (!(op->next = ft_bubble_group(n2)))
		return (-1);
	if (!(op->next->next = ft_merge_one(n3)))
		return (-1);
	ft_print_res(op);
	ft_del_ret(&op);
//	ft_del_num(&bgn);
//	ft_del_num(&n2);
//	ft_del_num(&n3);
	return (0);
}
