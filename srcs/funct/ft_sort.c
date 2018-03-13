/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:01:53 by jpinyot           #+#    #+#             */
/*   Updated: 2018/03/13 11:21:26 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static t_num	*ft_move(t_num *mv)
{
	t_num	*tmp;

	tmp = mv->prev;
	tmp->next = NULL;
	while (tmp != NULL)
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
		if (tmp->prev == NULL)
		{
			tmp->prev = mv;
			mv->prev = NULL;
			mv->next = tmp;
			break ;
		}
		tmp = tmp->prev;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_num	*ft_sort(t_num *num)
{
	t_num	*arr;
	t_num	*tmp;
	int	i;

	i = 0;
	tmp = num;
	arr = ft_lstnew_num(tmp->num, NULL);
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (!(arr->next = ft_lstnew_num(tmp->num, arr)))
			return (NULL);
		if (arr->num > arr->next->num)
			arr = ft_move(arr->next);
		else
			arr = arr->next;
		tmp = tmp->next;
	}
	while (arr->prev != NULL)
		arr = arr->prev;
	return (arr);
}
