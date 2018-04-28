/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_funct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:40:19 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/28 17:40:36 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	ft_chk_corr_ord(char **ord, int i)
{
	if (ft_strcmp(ord[i], "sa") == 0)
		return (1);	
	else if (ft_strcmp(ord[i], "sb") == 0)
		return (2);	
	else if (ft_strcmp(ord[i], "ss") == 0)
		return (3);	
	else if (ft_strcmp(ord[i], "pa") == 0)	
		return (4);	
	else if (ft_strcmp(ord[i], "pb") == 0)
		return (5);	
	else if (ft_strcmp(ord[i], "ra") == 0)
		return (6);	
	else if (ft_strcmp(ord[i], "rb") == 0)
		return (7);	
	else if (ft_strcmp(ord[i], "rr") == 0)
		return (8);	
	else if (ft_strcmp(ord[i], "rra") == 0)
		return (9);	
	else if (ft_strcmp(ord[i], "rrb") == 0)
		return (10);	
	else if (ft_strcmp(ord[i], "rrr") == 0)
		return (11);
	return (-1);	
}

void	ft_color_impl(t_stack *a, char **str, int i)
{
	int c;

	if ((c = ft_chk_corr_ord(str, i)) == 1 || c == 3 || c == 4 || c == 9 || c == 11)
		a->bgn->m = 2;
	if (c == 2 || c == 3 || c == 5 || c == 10 || c == 11)
		a->s_b->bgn->m = 2;
	if (c == 1 || c == 3)
		a->bgn->next->m = 2;
	if (c == 2 || c == 3)
		a->s_b->bgn->next->m = 2;
	if (c == 6 || c == 8)
		a->end->m = 2;
	if (c == 7 || c == 8)
		a->s_b->end->m = 2;
}

void	ft_color_del(t_stack *a, char **str, int i)
{
	int c;

	if ((c = ft_chk_corr_ord(str, i)) == 1 || c == 3 || c == 4 || c == 9 || c == 11)
		a->bgn->m = -1;
	if (c == 2 || c == 3 || c == 5 || c == 10 || c == 11)
		a->s_b->bgn->m = -1;
	if (c == 1 || c == 3)
		a->bgn->next->m = -1;
	if (c == 2 || c == 3)
		a->s_b->bgn->next->m = -1;
	if (c == 6 || c == 8)
		a->end->m = -1;
	if (c == 7 || c == 8)
		a->s_b->end->m = -1;
}

void	ft_read_nd_clear(void)
{
	char *b;

	b = NULL;
	while (read(1, b, 1) == 0)
	{
		if (b != NULL)
		{
			ft_strdel(&b);
			break ;
		}
	}
	ft_printf("\033[H\033[J");
}
