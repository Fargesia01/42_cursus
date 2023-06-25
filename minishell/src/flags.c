/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:37:58 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/12 15:32:49 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_flags(char *str, size_t i, t_line_flags *flags)
{
	if (flags->esc_char)
		flags->esc_char = !flags->esc_char;
	else if (str[i + 1] && str[i] == '\\' )
		flags->esc_char = !flags->esc_char;
	if ((i == 0 && str[i] == '\'')
		|| (i != 0 && str[i] == '\'' && str[i - 1] != '\\'
			&& !flags->doublequotes))
		flags->quotes = !flags->quotes;
	else if ((i == 0 && str[i] == '"')
		|| (i != 0 && str[i] == '"' && str[i - 1] != '\\'
			&& !flags->quotes))
		flags->doublequotes = !flags->doublequotes;
	else if (str[i] == '\\' && str[i + 1] == 0
		&& !flags->quotes && !flags->doublequotes && !flags->esc_char)
		flags->not_eol = !flags->not_eol;
	else if ((i != 0 && str[i] == '|' && !flags->esc_char
			&& !flags->quotes && !flags->doublequotes)
		|| flags->pipe && !ft_isspace(str[i]))
		flags->pipe = !flags->pipe;
	return (0);
}

int	skip_char(char *str, size_t i, t_line_flags *flags)
{
	if (!check_flags(str, i, flags) && flags->esc_char)
		return (1);
	if ((i == 0 && str[i] == '\'')
		|| (i != 0 && str[i] == '\''
			&& !flags->doublequotes && !flags->esc_char))
		return (1);
	else if ((i == 0 && str[i] == '"')
		|| (i != 0 && str[i] == '"'
			&& !flags->quotes && !flags->esc_char))
		return (1);
	else
		return (0);
}

size_t	strlen_wo_flags(char *str)
{
	size_t			i;
	size_t			j;
	t_line_flags	flags;

	i = 0;
	j = 0;
	ft_bzero(&flags, sizeof(t_line_flags));
	while (str[i])
	{
		if (! skip_char(str, i, &flags))
			j++;
		i++;
	}
	return (j);
}

char	*cpy_word(char *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			j;
	char			*out;
	t_line_flags	flags;

	i = 0;
	j = 0;
	ft_bzero(&flags, sizeof(t_line_flags));
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	out = ft_calloc((len + 1), sizeof(char));
	if (out == NULL)
		return (NULL);
	while (i < start)
		i++;
	while (i < (len + start))
	{
		if (! skip_char(s, i, &flags))
			out[j++] = s[i];
		i++;
	}
	return (out);
}

void	dup_flags(t_line_flags *outflags, t_line_flags *srcflags)
{
	outflags->quotes = srcflags->quotes;
	outflags->doublequotes = srcflags->doublequotes;
	outflags->not_eol = srcflags->not_eol;
	outflags->pipe = srcflags->pipe;
	outflags->esc_char = srcflags->esc_char;
}
