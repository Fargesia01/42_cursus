/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:41:38 by slott             #+#    #+#             */
/*   Updated: 2021/10/21 17:05:37 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_putnbr(long n, int c, char *tab);

char	*ft_itoa(int n)
{
	char	*tab;
	int		c;
	long	nbr;

	nbr = n;
	c = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		c++;
	}
	if (nbr == 0)
		c = 1;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		c++;
	}
	tab = malloc(c * sizeof(char) + 1);
	if (!(tab))
		return (NULL);
	ft_putnbr(n, c - 1, tab);
	tab[c] = 0;
	return (tab);
}

static	void	ft_putnbr(long n, int c, char *tab)
{
	if (n < 0)
	{
		tab[0] = 45;
		ft_putnbr(-n, c, tab);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, c - 1, tab);
		tab[c] = n % 10 + '0';
	}
	else
		tab[c] = n + '0';
}

/*int main()
{
	printf("%s", ft_itoa(-2147483648));	
}*/
