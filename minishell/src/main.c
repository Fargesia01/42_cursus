/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:56:47 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/16 19:16:49 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	free_exit(t_shell *sh);

void	init_term(void)
{
	struct termios	attributes;

	tcgetattr(STDIN_FILENO, &attributes);
	attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
	return ;
}

void	init_sh(t_shell *sh, char **envp)
{
	size_t	envp_len;

	sh->exit = 0;
	envp_len = ptablen((void **)envp);
	sh->envp = ft_calloc(envp_len + 1, sizeof(char *));
	sh->pi.n_commands = 0;
	sh->is_heredoc = 0;
	while (envp_len--)
		sh->envp[envp_len] = ft_strdup(envp[envp_len]);
	set_prompt(sh);
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	sh;

	init_term();
	init_sh(&sh, envp);
	setup_signals(&sh);
	while (! sh.exit)
	{
		if (!get_line(&sh))
		{
			if (sh.line[0])
				add_history(sh.line);
			lexer(&sh);
			if (!parser(&sh))
				exec(&sh);
			reset_command_table(&sh);
			sh.pi.n_commands = 0;
		}
	}
	free_exit(&sh);
	printf("exit\n");
	return (0);
}

static	void	free_exit(t_shell *sh)
{
	int	i;

	i = 0;
	while (sh->envp[i])
	{
		free(sh->envp[i]);
		i++;
	}
	free(sh->envp);
	free(sh->prompt);
}
