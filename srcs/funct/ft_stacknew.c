/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:28:07 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/01 17:44:23 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static t_stack	*ft_allocate_stack(t_num *n)
{
	t_stack	*s_a;
	t_stack	*s_b;
	t_num	*tmp;

	if (!(s_a = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	if (!(s_b = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	s_b->bgn = NULL;
	s_b->end = NULL;
	s_b->scnd = NULL;
	s_b->s_b = NULL;
	s_a->s_b = s_b;
	s_a->bgn = n;
	tmp = n;
	while (tmp->next != NULL)
		tmp = tmp->next;
	s_a->end = tmp;
	s_a->scnd = tmp->prev;
	return (s_a);
}

static t_stack	*ft_getpos(t_stack *s_a)
{
	t_num	*sort;
	t_num	*n;

	n = s_a->bgn;
	sort = ft_sort(s_a->bgn);
	while (sort)
	{

	}
	return (s_a);
}

t_stack			*ft_stacknew(t_num *n)
{
	t_stack	*s_a;
	t_stack *s_b;
	t_num	*sort;

	s_a = ft_allocate_stack(n);
	s_b = s_a->s_b;
	s_a = ft_getpos(s_a);
//	sort = ft_sort(n);
//	s_a->ref = sort;
//	s_b->ref = sort;
	return (s_a);
}
