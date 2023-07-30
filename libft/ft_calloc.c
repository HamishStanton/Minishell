/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:42:36 by hstanton          #+#    #+#             */
/*   Updated: 2022/03/29 16:49:33 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_calloc() function allocates memory. The ft_calloc() function
** contiguosly allocates enough space for "count" objects that are "size"
** bytes of memory each and returns a pointer to the allocated memory.
** The allocated memory is filled with bytes of value zero. If successful
** ft_calloc() returns a pointer to allocated memory. If there is an error,
** they return NULL pointer and set "errno" to ENOMEM.
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	b;
	void	*p;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	b = count * size;
	p = malloc(b);
	if (p == NULL)
		return (NULL);
	else
		ft_bzero(p, b);
	return (p);
}
