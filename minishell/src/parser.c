/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:26:30 by slott             #+#    #+#             */
/*   Updated: 2022/08/16 18:52:33 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/*
i = index de parsed_line
nbc = nombre commandes
arg = nombre argument
1. Check les erreurs de syntaxe
2. Malloc tout le necessaire
3. Parcours parsed_line et enregistre chaque chaine en fonction des signes de
redirections, pipe etc...
*/

int	parser(t_shell *sh)
{
	int	i;
	int	arg;
	int	nbc;

	i = 0;
	arg = 0;
	nbc = 0;
	if (!sh->parsed_line[0])
		return (1);
	if (check_errors(sh))
	{
		write(STDERR, "minipropre: syntax error\n", 25);
		return (1);
	}
	if (m_commands(sh))
		return (1);
	while (sh->parsed_line[i])
	{	
		if (get_operator(sh, &i, &arg, &nbc))
			return (1);
		i++;
	}
	return (0);
}

int	get_operator(t_shell *sh, int *i, int *arg, int *nbc)
{
	if (ft_strncmp(sh->parsed_line[*i], "|", 1) == 0)
	{
		(*arg) = 0;
		(*nbc)++;
	}
	else if (ft_strncmp(sh->parsed_line[*i], "<<", 2) == 0)
	{
		sh->command_table.commands[(*nbc)].infile
			= heredoc(sh, sh->parsed_line[++(*i)]);
		if (! sh->command_table.commands[(*nbc)].infile)
			return (1);
		sh->command_table.commands[(*nbc)].in = 1;
	}
	else if (ft_strncmp(sh->parsed_line[*i], ">>", 2) == 0)
	{
		if (check_outfile(sh, i, (*nbc)))
			return (1);
		sh->command_table.commands[(*nbc)].out = 1;
	}
	else
		return (get_operator_next(sh, i, arg, nbc));
	return (0);
}

int	get_operator_next(t_shell *sh, int *i, int *arg, int *nbc)
{
	if (ft_strncmp(sh->parsed_line[*i], "<>", 2) == 0)
	{
		if (create_outfile(sh->parsed_line[++(*i)]))
			return (1);
	}
	else if (ft_strncmp(sh->parsed_line[*i], "<", 1) == 0)
	{
		sh->command_table.commands[(*nbc)].infile = sh->parsed_line[++(*i)];
		sh->command_table.commands[(*nbc)].in = 0;
	}
	else if (ft_strncmp(sh->parsed_line[*i], ">", 1) == 0)
	{
		if (check_outfile(sh, i, (*nbc)))
			return (1);
		sh->command_table.commands[(*nbc)].out = 0;
	}
	else
	{
		sh->command_table.commands[(*nbc)].args[(*arg)] = sh->parsed_line[*i];
		(*arg)++;
	}
	return (0);
}

/*
 * Si un outfile est deja enregistre, ouvre/(creer) cet outfile avant 
 * de l'ecraser par le nouveau
 */

int	check_outfile(t_shell *sh, int *i, int nbc)
{
	int	fd;

	sh->command_table.commands[nbc].outfile = sh->parsed_line[++(*i)];
	if (create_outfile(sh->command_table.commands[nbc].outfile))
		return (1);
	return (0);
}
