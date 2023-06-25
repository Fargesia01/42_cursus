/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:09:52 by yoel              #+#    #+#             */
/*   Updated: 2022/08/05 15:34:31 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_line_flags	*parse_quotes(char *line, t_line_flags *flags)
{
	int				i;
	int				len;

	i = 0;
	len = ft_strlen(line);
	ft_bzero(flags, sizeof(t_line_flags));
	while (line[i])
		check_flags(line, i++, flags);
	return (flags);
}

int	squash(char **dest, char *add)
{
	char	*temp;

	temp = ft_strjoin(*dest, add);
	free(*dest);
	*dest = temp;
	return (0);
}

int	get_line(t_shell *sh)
{
	char			*line;
	t_line_flags	flag;

	sh->line = readline(sh->prompt);
	if (sh->line)
	{
		parse_quotes(sh->line, &flag);
		while (flag.quotes || flag.doublequotes || flag.not_eol || flag.pipe)
		{
			if (flag.not_eol)
			{
				flag.not_eol = !flag.not_eol;
				*ft_strrchr(sh->line, '\\') = 0;
			}
			if (flag.quotes || flag.doublequotes)
				squash(&sh->line, "\n");
			line = readline("> ");
			squash(&sh->line, line);
			free (line);
			parse_quotes(sh->line, &flag);
		}
		return (0);
	}
	sh->exit = 1;
	return (1);
}
