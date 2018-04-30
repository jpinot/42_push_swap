/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:51:21 by jpinyot           #+#    #+#             */
/*   Updated: 2018/04/30 16:25:40 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

static t_stack	*ft_order_cheker(t_stack *a, char **ord, t_ret *r, int i)
{
	if (ft_strcmp(ord[i], "sa") == 0 && a->bgn->next)
		return (ft_sa(a, r));
	else if (ft_strcmp(ord[i], "sb") == 0 && a->s_b->bgn->next)
		return (ft_sb(a->s_b, r));
	else if (ft_strcmp(ord[i], "ss") == 0 && a->bgn->next && a->s_b->bgn->next)
		return (ft_ss(a, r));
	else if (ft_strcmp(ord[i], "pa") == 0 && a->s_b->bgn)
		return (ft_pa(a, a->s_b, r));
	else if (ft_strcmp(ord[i], "pb") == 0 && a->bgn)
		return (ft_pb(a, a->s_b, r));
	else if (ft_strcmp(ord[i], "ra") == 0 && a->bgn->next)
		return (ft_ra(a, r));
	else if (ft_strcmp(ord[i], "rb") == 0 && a->s_b->bgn->next)
		return (ft_rb(a->s_b, r));
	else if (ft_strcmp(ord[i], "rr") == 0 && a->s_b->bgn->next && a->bgn->next)
		return (ft_rr(a, r));
	else if (ft_strcmp(ord[i], "rra") == 0 && a->bgn->next)
		return (ft_rra(a, r));
	else if (ft_strcmp(ord[i], "rrb") == 0 && a->s_b->bgn->next)
		return (ft_rrb(a->s_b, r));
	else if (ft_strcmp(ord[i], "rrr") == 0 && a->s_b->bgn->next && a->bgn->next)
		return (ft_rrr(a, r));
	else
		return (NULL);
	return (a);
}

static int		ft_checker(t_stack *a, char **ord, t_flag flag, t_ret *r)
{
	int		i;

	i = 0;
	while (ord[i])
	{
		if (ft_chk_corr_ord(ord, i) == -1)
			return (-1);
		if (!(ft_order_cheker(a, ord, r, i)))
			return (-1);
		if (flag.o == 1)
			ft_printf("\e[31m%s: \e[0m", ord[i]);
		if (flag.m == 0 && flag.o == 1)
			ft_printf("\n");
		if (flag.m == 1)
			ft_printf("\e[34m->%d<-\n\e[0m", i + 1);
		if (flag.v == 1)
			ft_print_stack(a);
		if (flag.v == 2)
			ft_print_stack_c(a, ord, i, flag);
		i++;
	}
	i = ft_chkr_sort(a);
	ft_del_stack(&a);
	return (i);
}

static char		**get_orders(void)
{
	char	*ret;
	char	*d;
	int		i;
	char	*buf;
	char	**r;

	i = 0;
	if (!(ret = ft_strnew(0)))
		return (NULL);
	if (!(buf = ft_strnew(5)))
		return (NULL);
	while (read(0, buf, 4))
	{
		d = ret;
		ret = ft_strjoin(ret, buf);
		ft_strdel(&d);
		buf = ft_memset(buf, 0, 5);
	}
	ft_strdel(&buf);
	r = ft_strsplit(ret, '\n');
	ft_strdel(&ret);
	return (r);
}

static int		del_struct(char **ord, t_ret *r)
{
	int i;

	i = -1;
	while (ord[++i])
		free(ord[i]);
	free(ord);
	ft_del_ret(&r);
	return (0);
}

int				checker(t_num *n, t_flag p)
{
	char	**ord;
	t_stack	*a;
	t_ret	*r;
	int		i;

	r = ft_ret_new(0);
	if (!(a = ft_stacknew(n)))
		return (-1);
	if (!(ord = get_orders()))
		return (-1);
	if (p.v == 1)
		ft_print_stack(a);
	if ((i = ft_checker(a, ord, p, r)) == 1)
	{
		if (p.l == 1)
			ft_printf("NUMBER OF MOVEMENTS: %d\n", r->mov);
		ft_printf("OK\n");
	}
	else if (i == 0)
		ft_printf("KO\n");
	else if (i == -1)
		ft_dprintf(2, "Error\n");
	return (del_struct(ord, r));
}
