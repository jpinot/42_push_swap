
#include "libswap.h"

t_ret	*ft_ret_new(int sort)
{
	t_ret *ret;

	if (!(ret = (t_ret *)malloc(sizeof(t_ret))))
		return (NULL);
	ret->next = NULL;
	if (sort)
		ret->sort = sort;
	else
		ret->sort = -1;
	ret->mov = 0;
	if (!(ret->tp = ft_strnew(4)))
		return (NULL);
	ret->tp = ft_strcpy(ret->tp, "str:");
	return (ret);
}
