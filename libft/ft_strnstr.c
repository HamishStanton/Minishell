/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:13:03 by hstanton          #+#    #+#             */
/*   Updated: 2022/03/29 16:12:56 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strnstr() function locates the first occurence of the
** NULL-terminated string needle in the string haystack, where not more than
** len characters are searched. Character that appear after a '\0' character
** are not searched. Since the ft_strnstr() function is a FreeBSD specific
** API, it should only be used when portability is not a concern. If needle
** is an empty string, haystack is returned; if needle occurs nowhere in
** haystack, NULL is returned; otherwise a pointer to the first character
** of the first occurence of needle is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle == NULL || needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle [j] && i + j < len)
			{
				if (needle[j + 1] == '\0')
					return ((char *)haystack + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
