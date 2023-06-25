/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:42:27 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/12 13:10:22 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*heredoc(t_shell *sh, char *magic_word)
{
	char	*file;
	char	*line;

	sh->is_heredoc = 1;
	rl_getc_function = getc;
	file = ft_strdup("");
	line = readline("> ");
	while (line && ft_strncmp(line, magic_word, ft_strlen(magic_word) + 1))
	{
		squash(&file, line);
		free(line);
		squash(&file, "\n");
		line = readline("> ");
	}
	rl_getc_function = rl_getc;
	if (last_signal(0) == SIGINT)
	{
		free(line);
		file = NULL;
	}
	sh->is_heredoc = 0;
	return (file);
}

void	pipe_heredoc(char *magic_word)
{
	int	ppp[2];

	pipe(ppp);
	ft_putstr_fd(magic_word, ppp[1]);
	free(magic_word);
	close(ppp[1]);
	dup2(ppp[0], STDIN);
	close(ppp[0]);
	return ;
}
