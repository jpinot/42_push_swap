/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:22:05 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/24 16:28:29 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>

int		main(void)
{
	int arr[1];

	int i = (sizeof(arr) / sizeof(int)) / 2;
	int j = ((sizeof(arr) / sizeof(int)) / 2) + ((sizeof(arr) / sizeof(int)) % 2);
	char c = i + '0';
	char d = j + '0';
	write(1, &c, 1);
	write(1, "\n", 1);
	write(1, &d, 1);
	while(1)
	{
	}
	return (0);
}
