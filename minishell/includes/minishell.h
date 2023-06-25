/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:53:29 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/16 18:56:14 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <termios.h>
# include <sys/wait.h>
# include "libft.h"

# define DEFAULT_PROMPT	"Minipropre $> "
# define STDIN 0
# define STDOUT 1
# define STDERR 2
//
// Define structs
//

typedef struct s_command
{
	int		out;
	int		in;
	char	*outfile;
	char	*infile;
	char	**args;
}				t_command;

typedef struct s_command_table
{
	t_command	*commands;
	char		*delimit;
}				t_command_table;

typedef struct s_pipex
{
	int		fdin;
	int		fdout;
	int		**p;
	pid_t	*pid;
	int		n_commands;
	char	*path;
}				t_pipex;

typedef struct s_shell
{
	char			**envp;
	char			*prompt;
	char			*line;
	char			**parsed_line;
	t_command_table	command_table;
	t_pipex			pi;
	int				is_heredoc;
	int				exec_res;
	int				exit;
}				t_shell;

typedef struct s_line_flags
{
	char	quotes;
	char	doublequotes;
	char	not_eol;
	char	pipe;
	char	esc_char;
}				t_line_flags;

// prompt.c
int		set_prompt(t_shell *sh);
// line.c
int		squash(char **dest, char *add);
int		get_line(t_shell *sh);
// lexer.c
int		lexer(t_shell *sh);
// lexer_ext.c
int		count_word(char *word);
char	*del_quotes(char *word);
int		ft_isredir(char *s, size_t i);
int		ft_ispipe(char *str, size_t i);
// parser.c
int		parser(t_shell *sh);
int		m_commands(t_shell *sh);
int		m_args(t_shell *sh, int index, int i);
int		launch_args(t_shell *sh);
int		get_operator(t_shell *sh, int *i, int *arg, int *nbc);
int		get_operator_next(t_shell *sh, int *i, int *arg, int *nbc);
int		check_outfile(t_shell *sh, int *i, int nbc);
int		check_errors(t_shell *sh);
int		check_redirections(t_shell *sh, int i);
// flags.c
int		check_flags(char *str, size_t i, t_line_flags *flags);
int		skip_char(char *str, size_t i, t_line_flags *flags);
size_t	strlen_wo_flags(char *str);
char	*cpy_word(char *s, unsigned int start, size_t len);
void	dup_flags(t_line_flags *outflags, t_line_flags *srcflags);
// exec.c
int		exec(t_shell *sh);
int		core_exec(t_shell *sh, t_pipex *pi, int i);
int		init_pipex(t_shell *sh, t_pipex *pi);
void	close_pipes(t_pipex *pi, int index);
int		count_commands(t_shell *sh);
int		redirections(t_shell *sh, t_pipex *pi, int index, int mode);
int		execution(t_shell *sh, t_pipex *pi, int index);
int		openfile(char *filename, int mode);
int		open_outfile(char *filename, int mode);
char	*get_path(char *envp[], char *cmd);
void	redir_none(t_shell *sh, t_pipex *pi, int index, int mode);
int		redir_infile(t_shell *sh, t_pipex *pi, int index, int mode);
int		redir_outfile(t_shell *sh, t_pipex *pi, int index, int mode);
int		redir_both(t_shell *sh, t_pipex *pi, int index, int mode);
int		check_builtins(t_shell *sh, t_pipex *pi, int i);
// signals.c
void	setup_signals(t_shell *sh);
int		last_signal(int sig);
// heredoc.c
char	*heredoc(t_shell *sh, char *magic_word);
void	pipe_heredoc(char *magic_word);
//vars.c
char	*repl_var(t_shell *sh, char *word);

//Utilitaire
char	*get_env(char **envp, char *name);
size_t	ptablen(void **tab);
void	ft_free(char **ptr);
void	reset_command_table(t_shell *sh);
int		create_outfile(char *filename);
//
// Builtins commands
//

int		c_echo(t_shell *sh, char **args);
int		c_cd(t_shell *sh, char *modif);
int		c_pwd(t_shell *sh);
int		c_unset(t_shell *sh, char **args);
int		c_env(t_shell *sh);
int		c_exit(t_shell *sh, t_pipex *pi);

// c_export.c
int		c_export(t_shell *sh, char **args);

#endif
