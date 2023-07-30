/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:00:59 by hstanton          #+#    #+#             */
/*   Updated: 2022/05/02 18:39:00 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function 'f' to each character of the string 's', and passing
** its index as first argument to create a new string (with malloc(3))
** resulting from successive applications of 'f'. Returns the string created
** from the successive applications of 'f'. Returns NULL if the allocation
** fails.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*n;
	size_t	strlen;

	i = -1;
	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	n = (char *)malloc(strlen + 1);
	if (!n)
		return (NULL);
	while (s[++i])
		n[i] = f(i, s[i]);
	n[i] = '\0';
	return (n);
}
