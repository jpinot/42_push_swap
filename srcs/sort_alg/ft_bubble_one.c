/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:01:14 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/19 18:08:20 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

t_ret	ft_bubble_one(t_num *bgn)
{
	int	p;
	t_ret	res;
	t_stack	*a;

	res.mov = 0;
	res.tp = (char *)malloc(sizeof(char) * 5);
	res.tp = ft_strcpy(res.tp, "str:");
//	if (!(a = ft_stacknew(bgn)))
//		return (NULL);
	a = ft_stacknew(bgn);
	p = 0;
	while (p != a->l -1)
	{
		if (ft_check_side(a, p) == 1)
		{
			while (a->bgn->pos != p)
				ft_ra(a, res);
//			ft_putnbr(a->bgn->num);
//			ft_putnbr(a->bgn->prev->num);
		}
		else
		{
			while (a->bgn->pos != p)
			{
			//	write (1, "$", 1);
				a = ft_rra(a, res);
			//	write (1, "%", 1);
			}
		}
//		write (1, "*", 1);
//		ft_putnbr(a->bgn->num);
//		write (1, "*", 1);
		ft_pb(a, a->s_b, res);
//		write (1, "(", 1);
//		ft_putnbr(a->s_b->bgn->num);
//		write (1, ")", 1);
		p++;
	}
	while (p > 0)
	{
//		ft_putnbr(a->s_b->bgn->num);
		ft_pa(a, a->s_b, res);
		p--;
	}
	while (p < a->l)
	{
		write(1, "\n", 1);
		ft_putnbr(a->bgn->num);
//		write(1, " ", 1);
//		ft_putnbr(a->bgn->pos);
		a->bgn = a->bgn->next;
		p++;
	}
//	write(1, "\n", 1);
//	ft_putstr(res.tp);
	return (res);
}
