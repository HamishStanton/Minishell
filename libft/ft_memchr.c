/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:42:07 by hstanton          #+#    #+#             */
/*   Updated: 2022/05/03 17:59:58 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memchr() function locates the first occurence of c (converted to
** an unsigned char) in string s. The ft_memchr() function returns a pointer
** to the byte located, or NULL if no such byte exists within n bytes.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	chr;

	i = 0;
	str = (unsigned char *) s;
	chr = (unsigned char) c;
	while (i < n)
	{
		if (*str == chr)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}
