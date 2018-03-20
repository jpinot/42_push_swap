/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:28:07 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/20 11:25:51 by jpinyot          ###   ########.fr       */
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

static t_stack	*ft_getpos(t_stack *s_a)
{
	int		p;
	int		g;
	int		pos;
	t_num	*sort;
	t_num	*tmp;
	t_num	*bgn;

	bgn = s_a->bgn;
	if (!(sort = ft_sort(bgn)))
		return (NULL);
	p = 0;
	g = 0;
	pos = 0;
	while (sort != NULL)
	{
		tmp = bgn;
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
	t_stack *s_b;

	if (!(s_a = ft_allocate_stack(n)))
		return (NULL);
	s_b = s_a->s_b;
	if (!(s_a = ft_getpos(s_a)))
		return (NULL);
	s_a->s_b->l = s_a->l;
	s_a->s_b->l_g = s_a->l_g;
//	while (s_a->bgn != NULL)
//	{
//		ft_putnbr(s_a->bgn->g);
//		write(1, " ", 1);
//		ft_putnbr(s_a->bgn->p);
//		write(1, " ", 1);
//		ft_putnbr(s_a->bgn->pos);
//		write(1, "\n", 1);
//		s_a->bgn = s_a->bgn->next;
//	}
	return (s_a);
}
