/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:48:35 by hstanton          #+#    #+#             */
/*   Updated: 2022/05/03 17:57:28 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strncmp() function lexicogrphically compares the null terminated
** strings s1 and s2. ft_strncmp() compares no more than n characters.
** Because ft_strncmp() is designed for comparing strings rather than binary
** data, characters that appear after a '\0' character are not compared.
** ft_strncmp() function returns an integer greater than, equal to, or less
** than 0, according to the string s1 is greater than, equal to, or less than
** the string s2. The comparison is done using unsigned characters, so that
** '\200' is greater than '\0'.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
