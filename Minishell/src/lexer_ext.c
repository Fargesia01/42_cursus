/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:33:58 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/16 18:56:47 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_word(char *word)
{
	size_t			i;
	size_t			j;
	t_line_flags	flags;
	t_line_flags	oflags;

	i = 0;
	j = 0;
	ft_bzero(&flags, sizeof(t_line_flags));
	dup_flags(&oflags, &flags);
	check_flags(word, i, &flags);
	while (word[i] && (flags.quotes || flags.doublequotes || flags.not_eol
			|| flags.esc_char || ! ft_isspace(word[i])))
	{
		if (! ((oflags.quotes != flags.quotes && word[i] == '\'')
				|| (oflags.doublequotes != flags.doublequotes
					&& word[i] == '"')))
			j++;
		dup_flags(&oflags, &flags);
		if (word[++i])
			check_flags(word, i, &flags);
	}
	return (j);
}

char	*del_quotes(char *word)
{
	size_t			i;
	size_t			j;
	char			*new_word;
	t_line_flags	flags;
	t_line_flags	oflags;

	i = 0;
	j = 0;
	ft_bzero(&flags, sizeof(t_line_flags));
	dup_flags(&oflags, &flags);
	check_flags(word, i, &flags);
	new_word = ft_calloc(sizeof(char), count_word(word) + 1);
	while (word[i] && (flags.quotes || flags.doublequotes || flags.not_eol
			|| flags.esc_char || ! ft_isspace(word[i])))
	{
		if (! ((oflags.quotes != flags.quotes && word[i] == '\'')
				|| (oflags.doublequotes != flags.doublequotes
					&& word[i] == '"')))
			new_word[j++] = word[i];
		dup_flags(&oflags, &flags);
		if (word[++i])
			check_flags(word, i, &flags);
	}
	free(word);
	return (new_word);
}

int	ft_isredir(char *s, size_t i)
{
	if (s[i] && (s[i] != '<' && s[i] != '>')
		&& (s[i + 1] == '<' || s[i + 1] == '>'))
		return (1);
	else if (s[i] && (s[i + 1] != '<' && s[i + 1] != '>')
		&& (s[i] == '<' || s[i] == '>'))
		return (1);
	return (0);
}

int	ft_ispipe(char *str, size_t i)
{
	if (str[i] == '|')
		return (1);
	else if (str[i] && str[i + 1] == '|')
		return (1);
	return (0);
}
