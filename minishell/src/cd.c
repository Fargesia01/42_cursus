/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 08:32:56 by slott             #+#    #+#             */
/*   Updated: 2022/08/16 19:34:36 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	void	replace_envp(t_shell *sh, char **tmp_old_pwd)
{
	char	*tmp_pwd;
	int		i;

	i = 0;
	tmp_pwd = getcwd(NULL, 0);
	while (sh->envp[i])
	{
		if (ft_strncmp(sh->envp[i], "OLDPWD=", 7) == 0)
		{
			free(sh->envp[i]);
			sh->envp[i] = ft_strjoin("OLDPWD=", *tmp_old_pwd);
		}
		else if (ft_strncmp(sh->envp[i], "PWD=", 4) == 0)
		{
			free(sh->envp[i]);
			sh->envp[i] = ft_strjoin("PWD=", tmp_pwd);
		}
		i++;
	}
	free(*tmp_old_pwd);
	free(tmp_pwd);
}

int	c_cd(t_shell *sh, char *modif)
{
	char	*tmp_pwd;
	char	*tmp_old_pwd;
	char	*pwd;
	char	*old_pwd;
	int		i;

	i = 0;
	if (!modif || modif[0] == '~')
	{
		if (chdir(get_env(sh->envp, "HOME")))
			return (printf("Minipropre: cd : HOME not set\n"));
	}
	else if (modif[0] == '-')
	{
		if (chdir(get_env(sh->envp, "OLDPWD")))
			return (printf("Minipropre: cd: OLDPWD not set\n"));
	}
	else if (chdir(modif))
		return (printf("cd: no such file or directory: %s\n", modif));
	tmp_old_pwd = getcwd(NULL, 0);
	replace_envp(sh, &tmp_old_pwd);
	return (0);
}
