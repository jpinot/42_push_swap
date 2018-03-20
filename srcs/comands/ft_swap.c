
#include "libswap.h"

t_stack	*ft_sa(t_stack *a, t_ret ret)
{
	t_num *tmp;
	char *d;

	tmp = a->bgn->next;
	a->bgn->prev = tmp;
	a->bgn->next = tmp->next;
	tmp->next = a->bgn;
	tmp->prev = NULL;
//	write(1, "$", 1);
	a->bgn = tmp;


	d = ret.tp;
	ret.tp = ft_strjoin(ret.tp, " sa");
	ret.mov += 1;
//	ft_strdel(&d);
	return (a);
}

t_stack	*ft_sb(t_stack *b, t_ret ret)
{
	t_num *tmp;
	char *d;

	tmp = b->bgn->next;
	b->bgn->prev = tmp;
	b->bgn->next = tmp->next;
	tmp->next = b->bgn;
	tmp->prev = NULL;
//	write(1, "$", 1);
	b->bgn = tmp;
	d = ret.tp;
	ret.tp = ft_strjoin(ret.tp, " sb");
	ret.mov += 1;
//	ft_strdel(&d);
	return (b);
}
