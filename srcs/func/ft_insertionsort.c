/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertionsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:56:53 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/26 17:51:34 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libswap.h"

static int	**ft_move(int **arr, int mv)
{
	int i;
	int tmp;
	int tmp2;

	i = mv - 1;
	tmp = arr[0][mv];
	while (tmp < arr[0][i - 1] && i > 0)
		i--;
	while (i <= mv)
	{
		tmp2 = arr[0][i];
		arr[0][i] = tmp;
		tmp = tmp2;
		i++;
	}
	return (arr);
}

int			*ft_sort(int **arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr[0][i] > arr[0][i + 1])
			arr = ft_move(arr, i + 1);
		i++;
	}
	i = 0;
	return (arr[0]);
}
#include <unistd.h>
#include <stdio.h>

int		main(void)
{
	int arr[10] = {2, 1, 3, 7, 4, 6, 8, 0, 5, 9};
	int i = 0;
	int *v = arr;
	int *str = ft_sort(&v, 10);
	char c;

	while (i < 10)
	{
		c = str[i] + '0';
		write(1, &c, 1);
		write (1, "  ", 2);
		printf("%i", str[i]);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
