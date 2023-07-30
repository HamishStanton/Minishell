/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:02:03 by hstanton          #+#    #+#             */
/*   Updated: 2022/05/02 18:55:29 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the character 'c' to the given file descriptor. Returns nothing.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
