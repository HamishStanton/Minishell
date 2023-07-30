/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:42:57 by hstanton          #+#    #+#             */
/*   Updated: 2022/03/07 18:48:16 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The ft_strrchr() function is indentical to strchr(), except it locates the
** last occurrence of c.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;

	a = NULL;
	if (c == '\0')
	{
		while (*s)
			s++;
		a = (char *)s;
		return (a);
	}
	while (*s)
	{
		if (*s == c)
			a = (char *)s;
		s++;
	}
	return (a);
}
