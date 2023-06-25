/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:39:56 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/12 13:38:52 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_shell	*mon_sauveur(t_shell *sh)
{
	static t_shell	*save;

	if (sh)
		save = sh;
	return (save);
}

static void	handler(int sig __attribute__((unused)), siginfo_t *siginfo,
				void *ucontext __attribute__((unused)))
{
	int		i;
	int		signal;
	t_shell	*sh;

	i = 0;
	sh = mon_sauveur(NULL);
	last_signal(siginfo->si_signo);
	if (siginfo->si_signo == SIGINT)
	{
		while (sh->pi.n_commands && sh->pi.pid[i])
			kill(sh->pi.pid[i++], signal);
		if (! sh->is_heredoc)
		{
			write(1, "\n", 1);
			if (! sh->pi.n_commands)
			{
				rl_on_new_line();
				rl_replace_line("", 0);
				rl_redisplay();
			}
		}
	}
}

void	setup_signals(t_shell *sh)
{
	struct sigaction	sa;

	mon_sauveur(sh);
	sa.sa_sigaction = &handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_NODEFER | SA_SIGINFO;
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
	return ;
}

int	last_signal(int sig)
{
	int			ret_sig;
	static int	last_sig;

	ret_sig = last_sig;
	if (sig)
		last_sig = sig;
	else
		last_sig = 0;
	return (ret_sig);
}
