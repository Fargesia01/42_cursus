/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:05:17 by slott             #+#    #+#             */
/*   Updated: 2022/08/16 19:16:00 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*get_env(char **envp, char *name)
{
	size_t	i;
	size_t	len;

	if (!name)
		return (NULL);
	i = 0;
	name = ft_strjoin(name, "=");
	len = ft_strlen(name);
	while (envp[i] && ft_strncmp(envp[i], name, len))
		i++;
	free(name);
	if (envp[i])
		return (&(envp[i][len]));
	return (NULL);
}

size_t	ptablen(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

/*
1. Free infile
2. Free outfile
3. Parcours la liste des commandes (i), pour chaque commande free tous
les arguments (j), puis free le tableau et finalement free la command_table
*/

void	reset_command_table(t_shell *sh)
{
	int	i;

	i = 0;
	while (sh->parsed_line[i])
	{
		free(sh->parsed_line[i]);
		i++;
	}
	free(sh->parsed_line);
	i = 0;
	while (i < sh->pi.n_commands)
	{
		free(sh->command_table.commands[i].args);
		i++;
	}
	if (sh->command_table.commands)
		free(sh->command_table.commands);
	sh->command_table.commands = NULL;
}

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

// Ouvre (creer) un outfile

int	create_outfile(char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT | O_RDWR, \
			S_IRUSR | S_IWUSR | S_IROTH);
	if (fd < 0)
	{
		write(STDERR, "Error while opening file\n", 25);
		return (1);
	}
	return (0);
}
