/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:16:26 by aalkaff           #+#    #+#             */
/*   Updated: 2025/09/15 22:17:22 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char			numbers[10];
	unsigned int	i;

	i = 0;
	while (i < 10)
	{
		numbers[i] = '0' + i;
		i++;
	}
	write(STDOUT_FILENO, numbers, 26);
}
