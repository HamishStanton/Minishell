/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:38:18 by hstanton          #+#    #+#             */
/*   Updated: 2022/04/29 16:33:49 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** The ft_strchr() function locates the first occurrence of c (converted to
** a char) in the string to by s. The terminating null character is
** considered to be part of the string; therefore if c is '\0', the functions
** locate the terminate '\0'. The function strchr() returns a pointer to the
** located characer, or NULL if the character does not appear in the string.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
