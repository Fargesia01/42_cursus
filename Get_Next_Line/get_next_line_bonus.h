/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:07:09 by slott             #+#    #+#             */
/*   Updated: 2021/12/07 14:41:06 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1

#endif

# include "stdio.h"
# include "unistd.h"
# include "fcntl.h"
# include "stdlib.h"

char	*get_next_line(int fd);
char	*get_next_line_suite(char **save, char **tab, int trigger, int fd);
char	*ft_strjoin(char *save, char *tab);
int		check_save(char *save);
char	*ft_trim(char *save);
void	free_ptr(char **ptr);
int		ft_strlen(char *str);
void	*ft_calloc(int size);

#endif
