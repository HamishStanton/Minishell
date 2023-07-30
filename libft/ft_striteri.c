/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:01:13 by hstanton          #+#    #+#             */
/*   Updated: 2022/05/03 18:21:40 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function 'f' on each character of the string passed as argument,
** passing its index as first argument. Each character is passed by address to
** 'f' to be modified if necessary. Returns nothing.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i++ < len)
		f(i - 1, &s[i - 1]);
}
