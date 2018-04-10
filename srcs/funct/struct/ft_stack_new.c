/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:28:07 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 18:57:28 by jpinyot          ###   ########.fr       */
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
	s_b->s_b = NULL;
	s_a->s_b = s_b;
	s_a->bgn = n;
	tmp = n;
	while (tmp->next != NULL)
		tmp = tmp->next;
	s_a->end = tmp;
	return (s_a);
}

static t_stack	*ft_getpos(t_stack *s_a, t_num *sort, int p, int g)
{
	int		pos;
	t_num	*tmp;

	pos = 0;
	while (sort != NULL)
	{
		tmp = s_a->bgn;
		while (sort->num != tmp->num)
			tmp = tmp->next;
		tmp->p = p;
		tmp->g = g;
		tmp->pos = pos;
		p++;
		pos++;
		s_a->l_g = g + 1;
		if (p == 3)
		{
			g++;
			p = 0;
		}
		sort = sort->next;
	}
	s_a->l = pos;
	return (s_a);
}

t_stack			*ft_stacknew(t_num *n)
{
	t_stack	*s_a;
	t_num	*sort;

	if (!(s_a = ft_allocate_stack(n)))
		return (NULL);
	if (!(sort = ft_sort(s_a->bgn)))
		return (NULL);
	if (!(s_a = ft_getpos(s_a, sort, 0, 0)))
		return (NULL);
	ft_del_num(&sort);
	return (s_a);
}
