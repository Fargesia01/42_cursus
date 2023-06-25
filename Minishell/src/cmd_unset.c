/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:20:23 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/15 19:38:36 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	c_unset(t_shell *sh, char **args)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!args[0])
	{
		write(1, "unset: not enough argument\n", 27);
		return (0);
	}
	while (args[i])
	{
		j = 0;
		while (sh->envp[j]
			&& ft_strncmp(sh->envp[j], args[i], ft_strlen(args[i])))
			j++;
		free(sh->envp[j]);
		while (sh->envp[j])
		{
			sh->envp[j] = sh->envp[j + 1];
			j++;
		}
		sh->envp[j] = NULL;
		i++;
	}
	return (0);
}
