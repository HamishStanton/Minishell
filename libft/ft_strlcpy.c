/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:25:26 by hstanton          #+#    #+#             */
/*   Updated: 2022/05/03 18:02:51 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strlcpy() copies up to dstsize - 1 character from the string src to dst,
** NUL-terminating the result if dstsize is not 0. If the src and dst strings
** overlap, the behavior is undefined. Note that room for the NUL should be
** included in dstsize. This process is destuctive.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
