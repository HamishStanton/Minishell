/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:53:16 by hstanton          #+#    #+#             */
/*   Updated: 2022/03/14 18:12:39 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long. The ft_memcmp() function
** returns zero if the two strings are identical, otherwise returns the
** difference between the first two differing bytes (treated as unsigned
** char values, so that '\200' is greater than '\0', for example).
** Zero-length strings are always identical. This behaviour is not required
** by C and portable code should only depend on the sign of the returned
** value.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	str1 = (char *) s1;
	str2 = (char *) s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char) str1[i] - (unsigned char) str2[i]);
		i++;
	}
	return (0);
}
