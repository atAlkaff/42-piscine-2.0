/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:40:31 by aalkaff           #+#    #+#             */
/*   Updated: 2025/09/16 14:32:04 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define BUFFER_SIZE 600

static char	*load_number(char *buffer, unsigned int digits[3])
{
	buffer[0] = digits[0] + '0';
	buffer[1] = digits[1] + '0';
	buffer[2] = digits[2] + '0';
	buffer[3] = ',';
	buffer[4] = ' ';
	return (buffer + 5);
}

void	ft_print_comb(void)
{
	char			buffer[BUFFER_SIZE];
	char			*iterator;
	unsigned int	digits[3];
	unsigned int	number;

	number = 12;
	iterator = buffer;
	while (number <= 789)
	{
		digits[0] = number / 100;
		digits[1] = (number % 100) / 10;
		digits[2] = number % 10;
		iterator = load_number(iterator, digits);
		if (digits[2] == 9)
		{
			if (digits[1] == 8)
				number += 11 * digits[0] + 34;
			else
				number += digits[1] + 3;
		}
		else
			number++;
	}
	write(STDOUT_FILENO, buffer, BUFFER_SIZE - 2);
}
