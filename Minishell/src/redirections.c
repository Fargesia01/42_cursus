/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:48:48 by slott             #+#    #+#             */
/*   Updated: 2022/08/05 16:20:00 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	redirections(t_shell *sh, t_pipex *pi, int index, int mode)
{
	if (!sh->command_table.commands[index].infile && \
			!sh->command_table.commands[index].outfile)
		redir_none(sh, pi, index, mode);
	else if (!sh->command_table.commands[index].outfile && \
			sh->command_table.commands[index].infile)
	{
		if (redir_infile(sh, pi, index, mode))
			return (1);
	}
	else if (!sh->command_table.commands[index].infile && \
			sh->command_table.commands[index].outfile)
	{
		if (redir_outfile(sh, pi, index, mode))
			return (1);
	}
	else
	{
		if (redir_both(sh, pi, index, mode))
			return (1);
	}
	return (0);
}

void	redir_none(t_shell *sh, t_pipex *pi, int index, int mode)
{
	if (pi->n_commands == 1)
		return ;
	else if (index == 0)
	{
		dup2(pi->p[index][1], STDOUT);
		if (mode == 0)
			close_pipes(pi, index);
	}
	else if (index == pi->n_commands - 1)
	{
		dup2(pi->p[index - 1][0], STDIN);
		if (mode == 0)
			close_pipes(pi, index - 1);
	}
	else
	{
		dup2(pi->p[index - 1][0], STDIN);
		dup2(pi->p[index][1], STDOUT);
		if (mode == 0)
		{
			close_pipes(pi, index);
			close_pipes(pi, index - 1);
		}
	}
}

int	redir_infile(t_shell *sh, t_pipex *pi, int index, int mode)
{
	if (sh->command_table.commands[index].in == 0)
	{
		pi->fdin = openfile(sh->command_table.commands[index].infile, STDIN);
		if (pi->fdin < 0)
			return (1);
		dup2(pi->fdin, STDIN);
		close(pi->fdin);
	}
	else if (sh->command_table.commands[index].in == 1)
		pipe_heredoc(sh->command_table.commands[index].infile);
	if (index != pi->n_commands - 1)
	{
		dup2(pi->p[index][1], STDOUT);
		if (mode == 0)
		{
			close(pi->p[index][1]);
			close(pi->p[index][0]);
		}
	}
	return (0);
}

int	redir_outfile(t_shell *sh, t_pipex *pi, int index, int mode)
{
	if (sh->command_table.commands[index].out == 0)
		pi->fdout = openfile(sh->command_table.commands[index].outfile, 1);
	else if (sh->command_table.commands[index].out == 1)
		pi->fdout = openfile(sh->command_table.commands[index].outfile, 2);
	if (pi->fdout < 0)
		return (1);
	dup2(pi->fdout, STDOUT);
	close(pi->fdout);
	if (index != 0)
	{
		dup2(pi->p[index - 1][0], STDIN);
		if (mode == 0)
		{
			close(pi->p[index - 1][0]);
			close(pi->p[index - 1][1]);
		}
	}
	return (0);
}

int	redir_both(t_shell *sh, t_pipex *pi, int index, int mode)
{
	int	ppp[2];

	if (sh->command_table.commands[index].out == 0)
		pi->fdout = openfile(sh->command_table.commands[index].outfile, 1);
	else if (sh->command_table.commands[index].out == 1)
		pi->fdout = openfile(sh->command_table.commands[index].outfile, 2);
	if (pi->fdout < 0)
		return (1);
	dup2(pi->fdout, STDOUT);
	close(pi->fdout);
	if (sh->command_table.commands[index].in == 0)
	{
		pi->fdin = openfile(sh->command_table.commands[index].infile, STDIN);
		if (pi->fdin < 0)
			return (1);
		dup2(pi->fdin, STDIN);
		close(pi->fdin);
	}
	else if (sh->command_table.commands[index].in == 1)
		pipe_heredoc(sh->command_table.commands[index].infile);
	return (0);
}
