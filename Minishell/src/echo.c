/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:31:55 by slott             #+#    #+#             */
/*   Updated: 2023/07/25 16:37:31 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	c_echo(t_shell *sh, char **args)
{
	int	i;
	int	option;

	i = 0;
	option = 0;
	if (!args[0])
	{
		printf("\n");
		return (0);
	}
	if (ft_strncmp(args[0], "-n", 2) == 0)
	{
		option = 1;
		i++;
	}
	while (args[i])
	{
		printf("%s ", args[i]);
		i++;
	}
	if (option == 0)
		printf("\n");
	return (0);
}
