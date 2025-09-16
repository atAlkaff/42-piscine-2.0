/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 23:55:00 by aalkaff           #+#    #+#             */
/*   Updated: 2025/09/16 23:55:15 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define BUFMAX 1764

static char	*store_number(int n, int *digits, char *it)
{
	int	i;

	i = 0;
	while (i < n)
		*it++ = digits[i++] + '0';
	*it++ = ',';
	*it++ = ' ';
	return (it);
}

static void	get_next_comb(int n, int *digits, int i)
{
	i++;
	while (i < n)
	{
		digits[i] = digits[i - 1] + 1;
		i++;
	}
}

static void	ft_print_combn(int n)
{
	char	buffer[BUFMAX];
	char	*it;
	int		digits[10];
	int		i;

	it = buffer;
	i = 0;
	while (i < n)
	{
		digits[i] = i;
		i++;
	}
	while (1)
	{
		it = store_number(n, digits, it);
		i = n - 1;
		while (i >= 0 && digits[i] == 10 - n + i)
			i--;
		if (i < 0)
			break ;
		digits[i]++;
		get_next_comb(n, digits, i);
	}
	write(STDOUT_FILENO, buffer, it - buffer - 2);
}
