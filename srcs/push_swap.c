	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:24:16 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/23 19:06:54 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	push_swap(t_num *bgn)
{
//	t_ret	op1;
	t_ret	*op;

//	if (!(s_a = ft_stacknew(bgn)))
//		return (-1);
//	op = ft_bubble_one(bgn);
//	op = ft_bubble_group(bgn);
	op = ft_merge_one(bgn);
//	op = ft_merge_group(bgn);
	write(1, " ", 1);
	ft_putnbr(op->mov);
	return (0);
}
