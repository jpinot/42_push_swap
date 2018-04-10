/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:51:17 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/10 18:57:30 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	push_swap(t_num *bgn)
{
	t_ret	*op1;
	t_ret	*op2;
	t_ret	*op3;

	if(!(op1 = ft_bubble_one(bgn)))
		return (-1);
	if(!(op2 = ft_bubble_group(bgn)))
		return (-1);
	if(!(op2 = ft_merge_one(bgn)))
		return (-1);


//	while(op)
//	{
//		write(1, " ", 1);
//		ft_putnbr(op1->mov);
//		write(1, " ", 1);
//		ft_putnbr(op2->mov);
//		write(1, " ", 1);
//		ft_putnbr(op3->mov);
//		op = op->next;
//	}
//	ft_del_ret(&op);
	return (0);
}
