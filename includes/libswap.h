/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libswap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:15:07 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/26 17:45:30 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

fndef LIBSWAP_H
# define LIBSWAP_H
# include "../libft/libft.h"

typedef struct	s_num
{
	int				num;
	int				g;
	struct s_num	*next;
}				t_num;

int         *ft_sort(int **arr, int size);
int			*ft_swap_stack(int **arr, int size);
#endif
