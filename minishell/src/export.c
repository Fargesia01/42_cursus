/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:07:09 by slott             #+#    #+#             */
/*   Updated: 2022/08/15 19:28:36 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

//1. Compter nombre ligne a rajouter dans env
//2. Re-malloc env et free l'ancien
//3. Rajouter les nouvelles variables

static int	add_variable(t_shell *sh, char *variable)
{
	char	**new;
	int		i;
	int		j;

	j = 0;
	i = ptablen((void **)sh->envp);
	new = ft_calloc(i + 2, sizeof(char *));
	ft_memcpy(new, sh->envp, i * sizeof(char *));
	new[i] = ft_strdup(variable);
	free(sh->envp);
	sh->envp = new;
	return (0);
}

static int	exists(char **envp, char *variable)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		if (!ft_strncmp(envp[i], variable, j + 1))
			return (i);
		i++;
	}
	return (0);
}

static int	change_value(t_shell *sh, char *variable)
{
	int	i;
	int	j;

	j = 0;
	i = exists(sh->envp, variable);
	free(sh->envp[i]);
	sh->envp[i] = ft_calloc(ft_strlen(variable) + 1, sizeof(char));
	if (!sh->envp[i])
		return (1);
	while (variable[j])
	{
		sh->envp[i][j] = variable[j];
		j++;
	}
	return (0);
}

static int	check_name(char *name)
{
	int	i;

	if (!ft_isalpha(name[0]))
		return (1);
	i = 0;
	while (name[i] && name[i] != '=')
	{
		if (!ft_isalnum(name[i]))
			return (1);
		i++;
	}
	return (0);
}

int	c_export(t_shell *sh, char **args)
{
	int	i;

	i = 0;
	if (!args[0])
		return (c_env(sh));
	while (args[i])
	{
		if (check_name(args[i]))
			printf("Minipropre: export: << %s >> : \
					identifiant non valable\n", args[i]);
		else if (exists(sh->envp, args[i]))
		{
			if (change_value(sh, args[i]))
				return (1);
		}
		else
		{
			if (add_variable(sh, args[i]))
				return (1);
		}
		i++;
	}
	return (0);
}
