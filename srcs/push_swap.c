	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:24:16 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/09 17:31:06 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	push_swap(t_num *bgn)
{
//	t_ret	op1;
	t_ret	*op;

//	op = ft_bubble_one(bgn);
//	op = ft_bubble_group(bgn);
	op = ft_merge_one(bgn);
//	op = ft_s_merge(bgn);
//	op = ft_merge_group(bgn);
	write(1, " ", 1);
	ft_putnbr(op->mov);
	return (0);
}
