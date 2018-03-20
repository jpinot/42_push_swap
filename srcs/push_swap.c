/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:24:16 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/20 21:10:22 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	push_swap(t_num *bgn)
{
//	t_ret	op1;
	t_ret	op2;

//	if (!(s_a = ft_stacknew(bgn)))
//		return (-1);
//	op1 = ft_bubble_one(bgn);
//	op2 = ft_bubble_group(bgn);
	op2 = ft_merge_one(bgn);
	return (0);
}
