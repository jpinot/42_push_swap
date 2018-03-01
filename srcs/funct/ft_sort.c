/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertionsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:56:53 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/27 16:34:34 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static t_num	*ft_move(t_num *mv)
{
	t_num	*tmp;
	t_num	*rtn;

	rtn = mv->prev;
	tmp = mv->prev;
	tmp->next = NULL;
	while (tmp->prev != NULL)
	{
		if (tmp->num < mv->num)
		{
			mv->next = tmp->next;
			mv->prev = tmp;
			tmp->next = mv;
			tmp = mv->next;
			tmp->prev = mv;
			break ;
		}
		tmp = tmp->prev;
	}
	return (rtn);
}

t_num	*ft_sort(t_num *num)
{
	t_num	*arr;
	t_num	*tmp;
	t_num	*rtn;
	int	i;

	i = 0;
	tmp = num;
	arr = ft_lstnew_num(tmp->num, 0, NULL);
	rtn = arr;
	while (tmp->next != NULL)
	{
		arr->next = ft_lstnew_num(tmp->next->num, 0, arr);
		if (arr->num > arr->next->num)
			arr = ft_move(arr->next);
		else
			arr = arr->next;
		tmp = tmp->next;
	}
	return (rtn);
}
