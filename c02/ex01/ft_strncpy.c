/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:46:20 by aalkaff           #+#    #+#             */
/*   Updated: 2025/09/20 19:51:17 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*dest_head;
	char	*end;

	dest_head = dest;
	end = dest + n;
	while (*src && dest < end)
		*dest++ = *src++;
	while (dest < end)
		*dest++ = 0;
	return (dest_head);
}
