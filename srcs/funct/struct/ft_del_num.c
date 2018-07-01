/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:10:15 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/29 16:29:09 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_del_num(t_num **lst)
{
	t_num *tmp;
	t_num *l;

	if (!(*lst))
		return ;
	l = *lst;
	while (l)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
	l = NULL;
}