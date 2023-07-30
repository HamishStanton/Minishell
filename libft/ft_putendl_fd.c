/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:02:55 by hstanton          #+#    #+#             */
/*   Updated: 2022/05/02 18:55:13 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the string 's' to the given file desciptor followed by a newline.
** Returns nothing.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
