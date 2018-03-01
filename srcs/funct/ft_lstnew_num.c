/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:22:44 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/27 18:04:47 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

t_num	*ft_lstnew_num(int num, t_num *p)
{
	t_num *list;

	if (!(list = (t_num *)malloc(sizeof(t_num))))
		return (NULL);
	if (p != NULL)
		list->prev = p;
	else
		list->prev = NULL;
	list->num = num;
	list->g = 0;
	list->stock = 0;
	list->pos = 0;
	list->next = NULL;
	return (list);
}
