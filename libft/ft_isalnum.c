/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:35:30 by hstanton          #+#    #+#             */
/*   Updated: 2022/05/03 17:31:49 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isalnum() function tests for any charcter for which isalpha(3) or
** is digit(3) is true. The value of the argument must be representable as
** an unsinged char or the value of EOF.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
	{
		return (1);
	}
	return (0);
}
