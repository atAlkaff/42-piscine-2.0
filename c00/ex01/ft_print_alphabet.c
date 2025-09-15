/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:09:54 by aalkaff           #+#    #+#             */
/*   Updated: 2025/09/15 22:12:21 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char			alphabets[26];
	unsigned int	i;

	i = 0;
	while (i < 26)
	{
		alphabets[i] = 'a' + i;
		i++;
	}
	write(STDOUT_FILENO, alphabets, 26);
}
