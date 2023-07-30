/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:50:45 by hstanton          #+#    #+#             */
/*   Updated: 2022/02/28 16:16:53 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memset() function writes len bytes of value c (converted to an
** unsigned char) to the string b. Returns it's first argument.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char		*str;
	size_t		i;

	str = (char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
