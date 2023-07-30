/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:28:35 by hstanton          #+#    #+#             */
/*   Updated: 2022/03/07 18:36:44 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The toupper() function converts a lower-case letter to the corresponding
   upper-case letter.  The argument must be representable as an unsigned
   char or the value of EOF.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
