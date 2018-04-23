#include "libswap.h"

int	ft_chk_corr_ord(char **ord, int i)
{
	if (ft_strcmp(ord[i], "sa") == 0)
		return (1);	
	else if (ft_strcmp(ord[i], "sb") == 0)
		return (1);	
	else if (ft_strcmp(ord[i], "ss") == 0)
		return (1);	
	else if (ft_strcmp(ord[i], "pa") == 0)	
		return (1);	
	else if (ft_strcmp(ord[i], "pb") == 0)
		return (1);	
	else if (ft_strcmp(ord[i], "ra") == 0)
		return (1);	
	else if (ft_strcmp(ord[i], "rb") == 0)
		return (1);	
	else if (ft_strcmp(ord[i], "rr") == 0)
		return (1);	
	else if (ft_strcmp(ord[i], "rra") == 0)
		return (1);	
	else if (ft_strcmp(ord[i], "rrb") == 0)
		return (1);	
	else if (ft_strcmp(ord[i], "rrr") == 0)
		return (1);	
	return (-1);	
}
