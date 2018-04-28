/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 17:47:36 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/21 19:09:34 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_print_stack(t_stack *stk)
{
	t_num *a;
	t_num *b;

	a = stk->bgn;
	b = stk->s_b->bgn;

	ft_printf("  STACK A  |  STACK B  \n");
	ft_printf("----------- -----------\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf("%-11d|", a->num);
			a = a->next;
		}
		else
			ft_printf("           |");
		if (b)
		{
			ft_printf("%-11d", b->num);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	ft_print_stack_c(t_stack *stk, char **str, int i, int p)
{
	t_num *a;
	t_num *b;

	a = stk->bgn;
	b = stk->s_b->bgn;
	ft_color_impl(stk, str, i);
	ft_printf("\e[32m  STACK A  |  STACK B  \e[0m\n");
	ft_printf("\e[32m----------- -----------\e[0m\n");
	while (a || b)
	{
		if (a && a->m == 2)
		{
			if (p == 0)
				ft_printf("\e[31m%-11d\e[32m|\e[0m", a->num);
			else
				ft_printf("\e[31m%-11d\e[32m|\e[0m", a->pos);
			a = a->next;
		}
		else if (a)
		{
			if (p == 0)
			ft_printf("%-11d\e[32m|\e[0m", a->num);
			else
			ft_printf("%-11d\e[32m|\e[0m", a->pos);
			a = a->next;
		}
		else
			ft_printf("\e[32m           |\e[0m");
		if (b && b->m == 2)
		{
			if (p == 0)
				ft_printf("\e[31m%d\e[0m", b->num);
			else
				ft_printf("\e[31m%d\e[0m", b->pos);
			b = b->next;
		}
		else if (b)
		{
			if (p == 0)
				ft_printf("%-11d", b->num);
			else
				ft_printf("%-11d", b->pos);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_color_del(stk, str, i);
	ft_printf("\n");
}
