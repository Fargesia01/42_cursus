/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:26:38 by slott             #+#    #+#             */
/*   Updated: 2022/08/15 19:36:20 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	void	free_pipex(t_pipex *pi);

/*
1. Initialise la struct pi
2. Parcours chaque commande avec la boucle while
3. Creer la pipe a son index
4. Fork
5. Child lance l'execution
6. Waitpid tout les childs
*/

int	exec(t_shell *sh)
{
	int		i;
	int		j;
	int		status;

	j = 0;
	i = 0;
	if (init_pipex(sh, &sh->pi))
		return (1);
	while (sh->command_table.commands[i].args)
	{
		if (core_exec(sh, &sh->pi, i++))
			return (1);
	}
	while (sh->pi.pid[j])
	{
		if (sh->pi.pid[j] > 0)
		{
			waitpid(sh->pi.pid[j], &status, 0);
			if (WIFEXITED(status))
				sh->exec_res = WEXITSTATUS(status);
		}
		j++;
	}
	free_pipex(&sh->pi);
	return (0);
}

int	core_exec(t_shell *sh, t_pipex *pi, int i)
{
	int	saved_stdout;
	int	saved_stdin;

	saved_stdout = dup(STDOUT);
	saved_stdin = dup(STDIN);
	if (pipe(pi->p[i]) < 0)
		return (write(STDERR, "Error while creating pipe\n", 26));
	if (check_builtins(sh, pi, i) == -1)
	{
		pi->pid[i] = fork();
		if (pi->pid[i] == 0 && execution(sh, pi, i))
			return (1);
	}
	else
	{
		dup2(saved_stdout, STDOUT);
		close(saved_stdout);
		dup2(saved_stdin, STDIN);
		close(saved_stdin);
	}
	if (i != 0)
		close_pipes(pi, i - 1);
	return (0);
}

/*
1. Lance les redirections
2. Enregistre le path avec get_path
3. Execute la commande
*/

int	execution(t_shell *sh, t_pipex *pi, int index)
{
	redirections(sh, pi, index, 0);
	if (ft_strncmp(sh->command_table.commands[index].args[0], "./", 2) == 0 || \
			ft_strncmp(sh->command_table.commands[index].args[0], "/", 1) == 0)
	{
		if (!access(sh->command_table.commands[index].args[0], F_OK))
			execve(sh->command_table.commands[index].args[0], \
					sh->command_table.commands[index].args, sh->envp);
		printf("Minipropre: %s: No such file or directory\n", \
				sh->command_table.commands[index].args[0]);
		free(sh->envp);
		exit(1);
	}
	pi->path = get_path(sh->envp, sh->command_table.commands[index].args[0]);
	if (!pi->path)
	{
		printf("minipropre: command not found: %s\n", \
				sh->command_table.commands[index].args[0]);
		reset_command_table(sh);
		exit (1);
	}
	execve(pi->path, sh->command_table.commands[index].args, sh->envp);
	free(pi->path);
	exit (1);
}

/*
1. Enregistre le nombre de commandes
2. Ouvre l'infile
3. Ouvre l'outfile
4. Malloc le tableau de int (tableau de pipe)
*/

int	init_pipex(t_shell *sh, t_pipex *pi)
{
	int	i;

	i = 0;
	pi->n_commands = count_commands(sh);
	pi->p = ft_calloc(pi->n_commands + 1, sizeof(int *));
	while (i < pi->n_commands)
		pi->p[i++] = ft_calloc(3, sizeof(int));
	pi->pid = ft_calloc((pi->n_commands + 1), sizeof(pid_t));
	if (!pi->pid)
		return (1);
	return (0);
}

static	void	free_pipex(t_pipex *pi)
{
	int	i;

	i = 0;
	while (pi->p[i])
	{
		free(pi->p[i]);
		i++;
	}
	free(pi->p);
	free(pi->pid);
}
