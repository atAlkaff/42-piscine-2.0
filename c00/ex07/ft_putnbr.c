/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:14:46 by aalkaff           #+#    #+#             */
/*   Updated: 2025/09/17 14:35:50 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

#define BUFMAX 20

void	ft_putnbr(int nb)
{
	char buffer[BUFMAX];
	int i;
	int is_negative;

	i = 19;
	buffer[i] = '0';
	if (nb == INT_MIN)
	{
		buffer[i--] = (unsigned int)nb % 10 + '0';
		nb /= 10;
	}
	is_negative = nb < 0;
	if (is_negative)
		nb = -nb;
	while (nb)
	{
		buffer[i--] = nb % 10 + '0';
		nb /= 10;
	}
	if (is_negative)
		buffer[i--] = '-';
	write(STDOUT_FILENO, buffer + i, BUFMAX - i);
}
