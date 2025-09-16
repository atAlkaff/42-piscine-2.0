/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:40:31 by aalkaff           #+#    #+#             */
/*   Updated: 2025/09/17 00:30:29 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define BUFMAX 600

static char	*store_number(int *digits, char *it)
{
	it[0] = digits[0] + '0';
	it[1] = digits[1] + '0';
	it[2] = digits[2] + '0';
	it[3] = ',';
	it[4] = ' ';
	return (it + 5);
}

static void	get_next_comb(int *digits, int i)
{
	i++;
	while (i < 3)
	{
		digits[i] = digits[i - 1] + 1;
		i++;
	}
}

void	ft_print_comb(void)
{
	char	buffer[BUFMAX];
	char	*it;
	int		digits[3];
	int		i;

	it = buffer;
	digits[0] = 0;
	digits[1] = 1;
	digits[2] = 2;
	while (1)
	{
		it = store_number(digits, it);
		i = 2;
		while (i >= 0 && digits[i] == 7 + i)
			i--;
		if (i < 0)
			break ;
		digits[i]++;
		get_next_comb(digits, i);
	}
	write(STDOUT_FILENO, buffer, it - buffer - 2);
}
