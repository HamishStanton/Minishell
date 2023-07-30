/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:37:59 by eclark            #+#    #+#             */
/*   Updated: 2023/07/30 17:38:19 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

char	**resplit_str(char **double_arr)
{
	char	**res;
	char	*joined_str;

	joined_str = join_split_str(double_arr, NULL);
	free_arr(double_arr);
	res = ft_split(joined_str, ' ');
	free(joined_str);
	joined_str = join_split_str(res, NULL);
	free_arr(res);
	res = ft_split(joined_str, ' ');
	free(joined_str);
	return (res);
}

char	*join_split_str(char **split_str, char *new_str)
{
	char	*tmp;
	char	*add_space;
	int		i;

	tmp = ft_strdup(split_str[0]);
	i = 1;
	while (split_str[i])
	{
		new_str = tmp;
		add_space = ft_strjoin(new_str, " ");
		free(new_str);
		tmp = ft_strjoin(add_space, split_str[i]);
		free(add_space);
		i++;
	}
	new_str = tmp;
	return (new_str);
}
