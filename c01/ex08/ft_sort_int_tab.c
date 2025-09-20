/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:25:20 by aalkaff           #+#    #+#             */
/*   Updated: 2025/09/20 19:39:08 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < size)
	{
		temp = tab[i];
		j = i;
		while (j > 0 && tab[j - 1] > temp)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = temp;
		i++;
	}
}
