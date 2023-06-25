/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:02:39 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/15 20:58:55 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	varlen(char *var)
{
	size_t	i;

	i = 0;
	if (var[i] && ! ft_isalpha(var[i]))
		return (i);
	i++;
	while (var[i] && (ft_isalnum(var[i]) || var[i] == '_'))
		i++;
	return (i);
}

char	*get_var_name(char *s_word)
{
	size_t	i;
	char	*varname;

	i = varlen(s_word);
	if (i == 0)
		return (ft_strdup(""));
	varname = ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(varname, s_word, i + 1);
	return (varname);
}

char	*sed(char *word, size_t idx, char *old, char *new)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	s;
	char	*new_w;

	i = 0;
	j = 0;
	k = 0;
	s = ft_strlen(word) - ft_strlen(old) - 1 + ft_strlen(new) + 2;
	new_w = ft_calloc(s, sizeof(char));
	while (i < idx)
		new_w[j++] = word[i++];
	while (new[k])
		new_w[j++] = new[k++];
	i += (ft_strlen(old) + 1);
	while (word[i])
		new_w[j++] = word[i++];
	free(new);
	free(old);
	return (new_w);
}

int	repl_word(t_shell *sh, char **word, size_t *i)
{
	char	*var;
	char	*value;
	char	*n_word;

	if ((*word)[*i + 1] == '?')
	{
		var = ft_strdup("?");
		value = ft_itoa(sh->exec_res);
	}
	else
	{
		var = get_var_name(*word + (*i + 1) * sizeof(char));
		value = get_env(sh->envp, var);
		if (value)
			value = ft_strdup(value);
	}
	if (! value)
		value = ft_strdup("");
	n_word = sed(*word, *i, var, value);
	free(*word);
	*word = n_word;
	*i += ft_strlen(value) - 1;
}

char	*repl_var(t_shell *sh, char *word)
{
	size_t			i;
	t_line_flags	flags;

	i = 0;
	ft_bzero(&flags, sizeof(t_line_flags));
	check_flags(word, i, &flags);
	while (word[i] && (flags.quotes || flags.doublequotes || flags.not_eol
			|| flags.esc_char || ! ft_isspace(word[i])))
	{
		if (word[i] == '$' && ! flags.quotes)
			repl_word(sh, &word, &i);
		if (word[++i])
			check_flags(word, i, &flags);
	}
	return (word);
}
