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
