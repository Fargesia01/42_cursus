/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:37:20 by slott             #+#    #+#             */
/*   Updated: 2021/10/14 17:23:55 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		x;

	d = (char *) dst;
	s = (const char *) src;
	x = 0;
	if (d < s)
	{
		while (x < size)
		{
			d[x] = s[x];
			x++;
		}
	}
	else if (d > s)
	{
		x = size;
		while (x > 0)
		{
			d[x - 1] = s[x - 1];
			x--;
		}
	}
	return (dst);
}

/*int main()
{
	char src[3] = "oki";
	char dst[30] = "123456789";
	printf("%s\n", dst);
	ft_memmove(dst, src, 5);
	printf("%s", dst);
}*/
