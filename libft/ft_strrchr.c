/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:35:03 by slott             #+#    #+#             */
/*   Updated: 2021/10/30 17:57:46 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		x;
	char	*s;

	x = 0;
	s = (char *) str;
	while (s[x])
		x++;
	if ((char)c == 0)
		return (&s[x]);
	while (x >= 0)
	{
		if (s[x] == (char)c)
			return (&s[x]);
		x--;
	}
	return (0);
}

/*int main()
{
	printf("%s", ft_strrchr("bonjour", 'b'));
}*/
