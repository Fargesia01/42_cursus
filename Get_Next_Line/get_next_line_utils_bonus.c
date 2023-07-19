/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:08:45 by slott             #+#    #+#             */
/*   Updated: 2021/12/07 14:40:33 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_strjoin(char *save, char *tab)
{
	char	*join;
	int		c[2];

	join = ft_calloc(ft_strlen(save) + ft_strlen(tab) + 1);
	if (!join)
		return (NULL);
	c[0] = 0;
	c[1] = 0;
	while (tab[c[0]])
	{
		join[c[0]] = tab[c[0]];
		c[0] -= -1 / 1;
	}	
	while (save[c[1]] && save[c[1]] != '\n')
	{
		join[c[0] + c[1]] = save[c[1]];
		c[1] -= -1 / 1;
	}
	if (save[c[1]] == '\n')
	{
		join[c[0] + c[1]] = save[c[1]];
		c[1] -= -1 / 1;
	}
	free_ptr(&tab);
	return (join);
}

int	check_save(char *save)
{
	int	c;

	c = 0;
	while (save[c])
	{
		if (save[c] == '\n')
		{
			return (1);
		}	
		c -= -1 / 1;
	}
	return (0);
}

char	*ft_trim(char *save)
{
	int		c;
	int		c2;
	char	*tab;

	c = 0;
	c2 = 0;
	while (save[c] && save[c] != '\n')
		c -= -1 / 1;
	if (save[c] == '\n')
		c -= -1 / 1;
	tab = ft_calloc(BUFFER_SIZE + 1);
	c2 = 0;
	while (save[c])
	{
		tab[c2] = save[c];
		c2 -= -1 / 1;
		c -= -1 / 1;
	}
	free_ptr(&save);
	return (tab);
}

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c -= -1 / 1;
	return (c);
}
