/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_group.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:35:25 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/23 14:06:56 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

t_ret	ft_bubble_group(t_num *bgn)
{
	int	p;
	int g;
	t_ret	res;
	t_stack	*a;

	res.mov = 0;
	res.tp = (char *)malloc(sizeof(char) * 5);
	res.tp = ft_strcpy(res.tp, "str:");
//	if (!(a = ft_stacknew(bgn)))
//		return (NULL);
	a = ft_stacknew(bgn);
	p = 0;
	g = 0;
//	ft_putnbr(a->l_g);
	while (g < (a->l_g - 1))
	{
		if (ft_check_side_g(a, g) == 1)
		{
			while (a->bgn->g != g)
				ft_ra(a, res);
		}
		else
		{
			while (a->bgn->g != g)
				a = ft_rra(a, res);
		}
		ft_pb(a, a->s_b, res);
		p++;
		if ( p == 3)
		{
			g += 1;
			p = 0;
		}
	}
//	a = ft_sa(a, res);
//	write(1, "$", 1);
	ft_group_one_sort(a, res);
	ft_group_sort(a, a->s_b, res);
//	while (p < a->l - 1)
//	{
//		ft_pa(a, a->s_b, res);
//		p++;
//	}
	while (a->s_b->bgn)
	{
		write(1, "\n", 1);
		ft_putnbr(a->s_b->bgn->num);
		write(1, " ", 1);
		ft_putnbr(a->s_b->bgn->p);
		write(1, " ", 1);
		ft_putnbr(a->s_b->bgn->g);
		a->s_b->bgn = a->s_b->bgn->next;
		p--;
	}
		write(1, "\n", 1);
		write(1, "----------", 10);
		write(1, "\n", 1);
	while (a->bgn)
	{
		write(1, "\n", 1);
		ft_putnbr(a->bgn->num);
		write(1, " ", 1);
		ft_putnbr(a->bgn->p);
		write(1, " ", 1);
		ft_putnbr(a->bgn->g);
		a->bgn = a->bgn->next;
		p--;
	}
//	write(1, "\n", 1);
//	ft_putstr(res.tp);
	return (res);
}
