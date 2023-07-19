/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:57:59 by slott             #+#    #+#             */
/*   Updated: 2022/03/01 14:10:59 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int		compteur_case(const char *s, char ch);
int		compteur_taille(const char *s, char ch);
void	ft_free(char **tab);
char	**ft_split_suite(char **tab, int x);

char	**ft_split(const char *s, char ch)
{
	char	**tab;
	int		c[2];

	c[0] = 0;
	c[1] = 0;
	if (!(s))
		return (NULL);
	tab = malloc((compteur_case(s, ch) + 1) * sizeof(char *));
	if (!(tab))
		return (NULL);
	while (*s)
	{
		if (*s != ch && c[1] == 0)
		{
			tab[c[0]] = malloc(compteur_taille(s, ch) * sizeof(char) + 1);
			if (!(tab[c[0]]))
				ft_free(tab);
			ft_strlcpy(tab[c[0]++], s, compteur_taille(s, ch) + 1);
			c[1]++;
		}
		else if (*s == ch && c[1] == 1)
			c[1] = 0;
		s++;
	}
	return (ft_split_suite(tab, c[0]));
}

char	**ft_split_suite(char **tab, int x)
{
	tab[x] = 0;
	return (tab);
}

void	ft_free(char **tab)
{
	int	x;

	x = 0;
	while (tab[x])
		free(tab[x]);
	free(tab);
}

int	compteur_taille(const char *s, char ch)
{
	int	c;

	c = 0;
	while (*s && *s == ch)
		s++;
	while (*s && *s != ch)
	{
		c++;
		s++;
	}
	return (c);
}

int	compteur_case(const char *s, char ch)
{
	int	x;
	int	bo;
	int	i;

	bo = 0;
	x = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != ch && bo == 0)
		{
			bo++;
			x++;
		}
		else if (s[i] == ch && bo == 1)
			bo = 0;
		i++;
	}
	return (x);
}

/*int main()
{
	int	x = 0;
	char **tab;
	
	tab = ft_split("1 2 3 4 5 6 ", ' ');
	while (tab[x])
	{
		printf("%s\n", tab[x]);
		x++;
	}	
}*/
