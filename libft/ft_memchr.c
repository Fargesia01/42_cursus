/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:59:03 by slott             #+#    #+#             */
/*   Updated: 2021/10/19 15:40:00 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	char	*s;
	size_t	x;

	x = 0;
	s = (char *) str;
	while (x < size)
	{
		if (s[x] == (char)c)
			return ((void *)(s + x));
		x++;
	}
	return (NULL);
}

/*int main()
{
	char str[] = {0 ,1 ,2 ,3 ,4 ,5};
	printf("%s", ft_memchr(str, 2 + 256, 3));	
}*/
