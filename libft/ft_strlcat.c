/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:09:43 by slott             #+#    #+#             */
/*   Updated: 2021/10/20 13:29:51 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	leng(const char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	y;

	y = 0;
	x = leng(dst);
	if (x > size || size == 0)
		return (leng(src) + size);
	while (x + y < size - 1 && src[y])
	{
		dst[x + y] = src[y];
		y++;
	}
	if (x + y < size)
		dst[x + y] = '\0';
	return (x + leng(src));
}

size_t	leng(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x])
	{
		x++;
	}
	return (x);
}

/*int main()
{
	char src[] = "toto";
	char dst[15] = "";
	printf("%s\n", dst);
	printf("%zu\n", ft_strlcat(dst, src, 0));
	printf("%s", dst);
}*/
