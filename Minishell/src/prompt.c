/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:27:02 by ycornamu          #+#    #+#             */
/*   Updated: 2022/07/01 16:36:26 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_prompt(t_shell *sh)
{
	sh->prompt = ft_strdup(DEFAULT_PROMPT);
	return (0);
}

//char	*prompt;
	//
	//prompt = get_env("PS1");
	//if (prompt)
	//	sh->prompt = prompt_parser(prompt);
	//else
	//	sh->prompt = ft_strdup("DEFAULT_PROMPT");
	//
