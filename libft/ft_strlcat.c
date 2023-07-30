/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:05:44 by hstanton          #+#    #+#             */
/*   Updated: 2022/03/07 18:27:55 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strlcat() appends string src to the end of dst. It will append at most
** dstsize - strlen(dst) - 1 characters. It will then NUL-terminate, unless
** dstsize is 0 or the original dst string was longer than dstsize
** (in practice this should not happen as it means that either dstsize is
** incorrect or that dst is not a proper string). If the src and dst strings
** overlap, the behavior is undefined.
*/

//Row 33: used to shift ft_ over by dstsize.

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
