
#include "libswap.h"

static t_stack	*ft_sort_top_three(t_stack *a, t_ret *ret, int p)
{
//	ft_putnbr(a->bgn->pos);
//	write(1, " ", 1);
//	ft_putnbr(a->bgn->next->pos);
//	write(1, " ", 1);
//	ft_putnbr(a->bgn->next->next->pos);
//	write(1, " ", 1);
//	ft_putnbr(a->bgn->next->next->next->m);
//	write(1, " ", 1);
//	ft_putnbr(p);
	if (a->bgn->pos == p)
	{
		ft_sa(a, ret);
		ft_ra(a, ret);
		ft_sa(a, ret);
		ft_rra(a, ret);
		if (a->bgn->pos > a->bgn->next->pos)
			ft_sa(a, ret);
	}
	else if (a->bgn->next->pos == p)
	{
		ft_ra(a, ret);
		ft_sa(a, ret);
		ft_rra(a, ret);
		if (a->bgn->pos > a->bgn->next->pos)
			ft_sa(a, ret);
	}
	else
	{
		if (a->bgn->pos > a->bgn->next->pos)
			ft_sa(a, ret);
	}
	return (a);
}

t_stack *ft_sort_top_a(t_stack *a, t_ret *ret, int pos)
{
	int m;

	m = ft_check_m(a);
	if (m == 1)
		return (a);
	else if (m == 2)
	{
		if (a->bgn->pos > a->bgn->next->pos)
			ft_sa(a, ret);
	}
	else
		a = ft_sort_top_three(a, ret, pos);
	a->bgn->m = -1;
	return (a);
}

t_stack *ft_sort_g_top_a(t_stack *a, t_ret *ret, int g)
{
	int i;
	int m;
	t_num *tmp;

	tmp = a->bgn;
	i = 0;
	m = ft_check_m(a);
	while(tmp != NULL && tmp->g == g)
	{
		if(tmp->pos > i)
			i = tmp->pos;
		tmp = tmp->next;
	}
	if (m == 1)
		return (a);
	else if (m == 2)
	{
		if (a->bgn->pos > a->bgn->next->pos)
			ft_sa(a, ret);
	}
	else
		a = ft_sort_top_three(a, ret, i);
	a->bgn->m = -1;
	return (a);
}
