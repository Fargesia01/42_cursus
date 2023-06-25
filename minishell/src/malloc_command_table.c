/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_command_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:43:01 by slott             #+#    #+#             */
/*   Updated: 2022/08/05 16:23:27 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

//Malloc le nombre de struct t_command necessaire
//i = index, c = nombre de commandes

int	m_commands(t_shell *sh)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (sh->parsed_line[i])
	{
		if (ft_strncmp(sh->parsed_line[i], "|", 1))
			c++;
		i++;
	}
	sh->command_table.commands = ft_calloc(c + 1, sizeof(t_command));
	if (!sh->command_table.commands)
		return (1);
	if (launch_args(sh))
		return (1);
	return (0);
}

//Pour chacune des commandes, lance m_args
//c = index de la commande actuelle

int	launch_args(t_shell *sh)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (sh->parsed_line[i])
	{
		if (m_args(sh, c, i))
			return (1);
		while (sh->parsed_line[i] && \
				ft_strncmp(sh->parsed_line[i], "|", 1) != 0)
			i++;
		if (sh->parsed_line[i] && ft_strncmp(sh->parsed_line[i], "|", 1) == 0)
		{
			i++;
			c++;
		}
	}
	return (0);
}

//Parcours et compte le nombre d'argument (+ commande) et le malloc  

int	m_args(t_shell *sh, int index, int i)
{
	int	c;

	c = 0;
	while (sh->parsed_line[i] && ft_strncmp(sh->parsed_line[i], "|", 1) != 0)
	{
		if (ft_strpbrk(sh->parsed_line[i], "<>") != 0)
			i++;
		else
			c++;
		i++;
	}
	sh->command_table.commands[index].args = ft_calloc(c + 1, sizeof(char *));
	if (!sh->command_table.commands[index].args)
		return (1);
	return (0);
}
