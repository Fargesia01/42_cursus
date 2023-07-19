/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:05:53 by slott             #+#    #+#             */
/*   Updated: 2021/12/07 14:40:19 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*tab;
	int			trigger;
	static char	*save[4097];

	trigger = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	tab = ft_calloc(1);
	if (!save[fd])
		save[fd] = ft_calloc(BUFFER_SIZE + 1);
	else
	{
		if (check_save(save[fd]))
			trigger = 1;
		tab = ft_strjoin(save[fd], tab);
	}
	return (get_next_line_suite(&save[fd], &tab, trigger, fd));
}

char	*get_next_line_suite(char **save, char **tab, int trigger, int fd)
{
	int	lu;

	lu = 0;
	while (!check_save(*save) && trigger == 0)
	{
		lu = read(fd, *save, BUFFER_SIZE);
		if (lu < BUFFER_SIZE && lu > 0)
			(*save)[lu] = 0;
		if (lu != 0)
			*tab = ft_strjoin(*save, *tab);
		else
			trigger = 2;
	}
	if ((*save)[0] == 0 && trigger == 2)
	{
		free_ptr(save);
		free_ptr(tab);
		return (NULL);
	}
	*save = ft_trim(*save);
	return (*tab);
}

void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	*ft_calloc(int size)
{
	char	*tab;
	int		c;

	c = 0;
	tab = malloc(size * sizeof(char));
	if (!tab)
		return (NULL);
	while (c < size)
	{
		tab[c] = 0;
		c -= -1 / 1;
	}
	return (tab);
}

/*int	main()
{
	int fd;
	char *tab;

	fd = open("test", O_RDWR | O_APPEND);
	//tab = get_next_line(fd);
	//tab = get_next_line(fd);
	//tab = get_next_line(fd);
	//printf("%s", tab);
	//tab = get_next_line(fd);
	//printf("%s", tab);
	tab = get_next_line(fd);
	tab = get_next_line(fd);
	tab = get_next_line(fd);
	tab = get_next_line(fd);
	tab = get_next_line(fd);
	//tab = get_next_line(fd);
	//tab = get_next_line(fd);
	printf("%s", tab);
	close(fd);
}*/
