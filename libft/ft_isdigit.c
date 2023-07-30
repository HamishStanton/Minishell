/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:28:25 by hstanton          #+#    #+#             */
/*   Updated: 2022/05/03 17:41:12 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isdigit() function test for a decimal digit character. Regardless of
** locale, this includes the following characters only: '0' - '9'
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
