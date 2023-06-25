/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:49:57 by slott             #+#    #+#             */
/*   Updated: 2022/08/16 18:54:51 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/*
 * 1.Check si ligne commence par pipe
 * 2.Pour chaque redirections check la syntaxe
 * 3.Pour chaque redirection controle que string suivante valable
 */

int	check_errors(t_shell *sh)
{
	int	i;

	i = 0;
	if (ft_strncmp(sh->parsed_line[0], "|", 1) == 0)
		return (1);
	while (sh->parsed_line[i])
	{
		if (ft_strpbrk(sh->parsed_line[i], "<>") != 0)
		{
			if (check_redirections(sh, i))
				return (1);
			else if (!sh->parsed_line[i + 1] || \
					ft_strpbrk(sh->parsed_line[i + 1], "<>|"))
				return (1);
		}
		else if (sh->parsed_line[i][0] == '|' \
				&& sh->parsed_line[i - 1][0] == '|')
			return (1);
		i++;
	}
	return (0);
}

/*
* Controle la syntaxe de la redirection
*/

int	check_redirections(t_shell *sh, int i)
{
	int	j;
	int	c;

	c = 0;
	j = 0;
	if (ft_strlen(sh->parsed_line[i]) > 1)
	{
		if (sh->parsed_line[i][j] == '>' && sh->parsed_line[i][j + 1] == '<')
			return (1);
		if (ft_strlen(sh->parsed_line[i]) > 3)
			return (1);
		if (ft_strlen(sh->parsed_line[i]) > 2 && (sh->parsed_line[i][j] != '<'\
					|| sh->parsed_line[i][j + 1] != '<' \
					|| sh->parsed_line[i][j + 2] != '<'))
			return (1);
	}
	return (0);
}
