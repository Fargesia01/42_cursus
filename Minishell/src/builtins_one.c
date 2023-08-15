/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:24:24 by slott             #+#    #+#             */
/*   Updated: 2023/07/25 16:37:16 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	check_builtins_next(t_shell *sh, t_pipex *pi, int i);

int	c_env(t_shell *sh)
{
	int	i;

	i = 0;
	while (sh->envp[i])
	{
		printf("%s\n", sh->envp[i]);
		i++;
	}
	return (0);
}

int	c_pwd(t_shell *sh)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}

int	c_exit(t_shell *sh, t_pipex *pi)
{
	if (pi->n_commands > 1)
		return (0);
	sh->exit = 1;
	return (0);
}	

int	check_builtins(t_shell *sh, t_pipex *pi, int i)
{
	pi->pid[i] = -1;
	if (!sh->command_table.commands[i].args[0])
		return (1);
	if (ft_strncmp(sh->command_table.commands[i].args[0], "env", 4) == 0)
	{
		redirections(sh, pi, i, 1);
		return (sh->exec_res = c_env(sh));
	}
	else if (ft_strncmp(sh->command_table.commands[i].args[0], "pwd", 4) == 0)
	{
		redirections(sh, pi, i, 1);
		return (sh->exec_res = c_pwd(sh));
	}
	else if (ft_strncmp(sh->command_table.commands[i].args[0], "unset", 6) == 0)
	{
		redirections(sh, pi, i, 1);
		return (sh->exec_res = c_unset(sh,
				&sh->command_table.commands[i].args[1]));
	}
	else
		return (check_builtins_next(sh, pi, i));
}

static int	check_builtins_next(t_shell *sh, t_pipex *pi, int i)
{
	if (ft_strncmp(sh->command_table.commands[i].args[0], "export", 7) == 0)
	{
		redirections(sh, pi, i, 1);
		return (sh->exec_res = c_export(sh,
				&sh->command_table.commands[i].args[1]));
	}
	else if (ft_strncmp(sh->command_table.commands[i].args[0], "exit", 5) == 0)
	{
		redirections(sh, pi, i, 1);
		return (sh->exec_res = c_exit(sh, pi));
	}
	else if (ft_strncmp(sh->command_table.commands[i].args[0], "cd", 3) == 0)
	{
		redirections(sh, pi, i, 1);
		return (sh->exec_res = c_cd(sh, sh->command_table.commands[i].args[1]));
	}
	else if (ft_strncmp(sh->command_table.commands[i].args[0], "echo", 5) == 0)
	{
		redirections(sh, pi, i, 1);
		return (sh->exec_res = c_echo(sh,
				&sh->command_table.commands[i].args[1]));
	}
	else
		return (-1);
}
