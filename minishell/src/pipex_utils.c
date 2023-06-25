/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:16:33 by slott             #+#    #+#             */
/*   Updated: 2022/08/15 19:30:44 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	count_commands(t_shell *sh)
{
	int	i;

	i = 0;
	while (sh->command_table.commands[i].args)
		i++;
	return (i);
}

void	close_pipes(t_pipex *pi, int index)
{
	close(pi->p[index][0]);
	close(pi->p[index][1]);
}

int	openfile(char *filename, int mode)
{
	int	fd;

	if (mode == STDIN)
	{
		if (access(filename, F_OK))
		{
			write(STDERR, "Infile fichier introuvable\n", 27);
			return (-1);
		}
		fd = open(filename, O_RDONLY);
		if (fd < 0)
		{
			write(STDERR, "Error while opening infile\n", 27);
			return (-1);
		}
		return (fd);
	}
	else
		return (open_outfile(filename, mode));
}

int	open_outfile(char *filename, int mode)
{
	int	fd;

	if (mode == 1)
		fd = open(filename, O_CREAT | O_RDWR | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else if (mode == 2)
		fd = open(filename, O_CREAT | O_RDWR | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
	{
		write(STDERR, "Error while opening outfile\n", 28);
		return (-1);
	}
	return (fd);
}

char	*get_path(char *envp[], char *cmd)
{
	int		i;
	char	**paths;
	char	*tmp;
	char	*command;

	paths = ft_split(get_env(envp, "PATH"), ':');
	i = 0;
	while (paths && paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(command, F_OK))
			break ;
		free(command);
		i++;
	}
	i = 0;
	while (paths && paths[i])
		free(paths[i++]);
	free(paths);
	if (!access(command, F_OK))
		return (command);
	return (NULL);
}
