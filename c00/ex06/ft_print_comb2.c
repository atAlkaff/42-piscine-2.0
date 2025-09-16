/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 00:37:07 by aalkaff           #+#    #+#             */
/*   Updated: 2025/09/16 14:48:21 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define BUFFER_SIZE 34650

static char *load_numbers(char *buffer, int a, int b)
{
	buffer[0] = a / 10 + '0';
	buffer[1] = a % 10 + '0';
	buffer[2] = ' ';
	buffer[3] = b / 10 + '0';
	buffer[4] = b % 10 + '0';
	buffer[5] = ',';
	buffer[6] = ' ';
	return (buffer + 7);
}

void ft_print_comb2(void)
{
	char			buffer[BUFFER_SIZE];
	char			*iterator;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	iterator = buffer;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			iterator = load_numbers(iterator, i, j);
			j++;
		}
		i++;
	}
	write(STDOUT_FILENO, buffer, BUFFER_SIZE - 2);
}
