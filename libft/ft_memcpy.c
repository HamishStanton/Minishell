/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:18:26 by hstanton          #+#    #+#             */
/*   Updated: 2022/05/03 18:01:49 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memcpy() function copies n bytes from memory area src to memory area
** dst. If dst and src overlap, behavior is undefined. Returns the original
** value of dst.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dst);
}
