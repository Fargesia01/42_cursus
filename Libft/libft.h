/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:37:12 by slott             #+#    #+#             */
/*   Updated: 2021/11/04 16:24:49 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_bzero(void *str, size_t size);
int		ft_isalnum(int x);
int		ft_isalpha(int x);
int		ft_isascii(int x);
int		ft_isdigit(int x);
int		ft_isprint(int x);
void	*ft_memchr(const void *str, int c, size_t size);
int		ft_memcmp(const void *str1, const void *str2, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t size);
void	*ft_memset(void *str, int c, size_t size);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *hay, const char *nee, size_t size);
char	*ft_strrchr(const char *str, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *str);
void	*ft_calloc(size_t c, size_t size);
char	*ft_substr(char const *str, unsigned int x, size_t len);
char	*ft_strjoin(char const *pre, const char *su);
char	*ft_strtrim(const char *str, const char *list);
char	*ft_itoa(int n);
char	**ft_split(const char *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
