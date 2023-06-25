/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:02:52 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/16 18:54:13 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_strcntword(char *s)
{
	size_t			i;
	size_t			nb_words;
	t_line_flags	flags;

	i = 0;
	nb_words = 0;
	ft_bzero(&flags, sizeof(t_line_flags));
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i])
		{
			while (s[i] && (flags.quotes || flags.doublequotes || flags.not_eol
					|| flags.esc_char || ! ft_isspace(s[i]))
				&& ! ((ft_ispipe(s, i) || ft_isredir(s, i)) && ! flags.quotes
					&& ! flags.doublequotes && ! flags.esc_char))
				check_flags(s, i++, &flags);
			if ((ft_ispipe(s, i) || ft_isredir(s, i)) && ! flags.quotes
				&& ! flags.doublequotes && ! flags.esc_char)
				check_flags(s, i++, &flags);
			nb_words++;
		}
	}
	return (nb_words);
}

static size_t	ft_strdlen(char *s)
{
	size_t			i;
	t_line_flags	flags;

	i = 0;
	ft_bzero(&flags, sizeof(t_line_flags));
	while (s[i] && (flags.quotes || flags.doublequotes || flags.not_eol
			|| flags.esc_char || ! ft_isspace(s[i]))
		&& ! ((s[i] == '|' || s[i] == '<' || s[i] == '>')
			&& ! flags.quotes && ! flags.doublequotes && ! flags.esc_char))
		check_flags(s, i++, &flags);
	if (i == 0 && s[i] == '|')
		return (1);
	if (i == 0 && (s[i] == '<' || s[i] == '>'))
	{
		while (s[i] == '<' || s[i] == '>')
			i++;
	}
	return (i);
}

static int	ft_skipchar(char *s, int i)
{
	while (s[i] && ft_isspace(s[i]))
		i++;
	return (i);
}

char	**split_str(t_shell *sh, char *s)
{
	int		wrd_size;
	int		j;
	int		offset;
	char	**tab;
	char	*word;

	if (!s)
		return (NULL);
	offset = 0;
	j = ft_strcntword(s);
	tab = ft_calloc(j + 1, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab[j--] = NULL;
	while (j >= 0)
	{
		offset = ft_skipchar(s, offset);
		wrd_size = ft_strdlen((s + offset));
		word = ft_substr(s, offset, wrd_size);
		if (word == NULL)
			return (NULL);
		tab[ft_strcntword(s) - j-- - 1] = del_quotes(repl_var(sh, word));
		offset += wrd_size;
	}
	return (tab);
}

int	lexer(t_shell *sh)
{
	sh->parsed_line = split_str(sh, sh->line);
	free(sh->line);
	sh->line = NULL;
	return (0);
}
