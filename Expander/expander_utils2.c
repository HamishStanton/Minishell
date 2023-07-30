/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <hstanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:17:14 by hstanton          #+#    #+#             */
/*   Updated: 2023/07/30 16:56:28 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

int	question_mark(char **tmp)
{
	free(*tmp);
	*tmp = ft_itoa(g_global.error_num);
	return (ft_strlen(*tmp) + 1);
}
