/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkaff <aalkaff@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:06:56 by aalkaff           #+#    #+#             */
/*   Updated: 2025/09/20 21:05:13 by aalkaff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_UPPER	1
#define FT_LOWER	2
#define FT_DIGIT	4

#define FT_TOLOWER	5
#define FT_TOUPPER	4

static void	generate_alnums(unsigned char *alnum)
{
	unsigned char	i;

	i = '0';
	while (i <= '9')
		alnum[i++] = FT_DIGIT;
	i = 'A';
	while (i <= 'Z')
		alnum[i++] = FT_UPPER;
	i = 'a';
	while (i <= 'z')
		alnum[i++] = FT_LOWER;
}

char	*ft_strcapitalize(char *str)
{
	static unsigned char	alnum[256] = {0};
	int						i;
	int						prev;
	int						curr;

	if (!alnum['A'])
		generate_alnums(alnum);
	i = 0;
	prev = 0;
	while (str[i])
	{
		curr = alnum[(unsigned char) str[i]];
		if (prev)
			str[i] |= (curr & FT_UPPER) << FT_TOLOWER;
		else
			str[i] &= ~((curr & FT_LOWER) << FT_TOUPPER);
		prev = curr;
		i++;
	}
	return (str);
}
