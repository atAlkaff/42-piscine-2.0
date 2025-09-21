/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:23:08 by aalkaff           #+#    #+#             */
/*   Updated: 2025/09/21 21:05:35 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define BUFSIZE	1024
#define HEX		"0123456789abcdef"

static void	ft_putchar_buf(char c, unsigned int flush)
{
	static char	buf[BUFSIZE];
	static int	size = 0;

	if (flush)
	{
		if (size > 0)
			write(STDOUT_FILENO, buf, size);
		size = 0;
		return;
	}
	buf[size++] = c;
	if (size == BUFSIZE)
	{
		write(STDOUT_FILENO, buf, size);
		size = 0;
	}
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	uc;

	while (*str)
	{
		uc = (unsigned char)*str;
		if (uc - 32 < 95)
			ft_putchar_buf(uc, 0);
		else
		{
			ft_putchar_buf('\\', 0);
			ft_putchar_buf(HEX[uc >> 4], 0);
			ft_putchar_buf(HEX[uc & 15], 0);
		}
		str++;
	}
	ft_putchar_buf(0, 1);
}
