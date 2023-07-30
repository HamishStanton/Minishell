/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:02:28 by hstanton          #+#    #+#             */
/*   Updated: 2022/05/02 18:47:04 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the string 's' to the given file descriptor. Returns nothing.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
