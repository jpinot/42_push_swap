
#include "libswap.h"

t_stack		*ft_ra(t_stack *a, t_ret ret)
{
	t_num *tmp;
	char *del;

//	write (1, "(", 1);
//	ft_putnbr(a->bgn->num);
//	write (1, ")", 1);

	tmp = a->bgn->next;
	a->bgn->next = NULL;
	a->bgn->prev = a->end;
	a->end->next = a->bgn;
	a->end = a->bgn;
	a->bgn = tmp;
	a->bgn->prev = NULL;
	del = ret.tp;
	ret.tp = ft_strjoin(ret.tp, " ra");
	ret.mov += 1;
//	ft_strdel(&del);

//	write (1, "(", 1);
//	ft_putnbr(a->bgn->next->num);
//	write (1, ")", 1);
	return (a);
}

t_stack		*ft_rb(t_stack *b, t_ret ret)
{
	t_num *tmp;
	char *del;

	tmp = b->bgn->next;
	b->bgn->next = NULL;
	b->bgn->prev = b->end;
	b->end->next = b->bgn;
	b->end = b->bgn;
	b->bgn = tmp;
	b->bgn->prev = NULL;
	del = ret.tp;
	ret.tp = ft_strjoin(ret.tp, " rb");
	ret.mov += 1;
//	ft_strdel(&del);
	return (b);
}


