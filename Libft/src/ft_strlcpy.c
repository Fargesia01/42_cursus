/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:18:33 by slott             #+#    #+#             */
/*   Updated: 2021/10/14 12:29:04 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	x;

	x = 0;
	if (size > 0)
	{
		while (x < size - 1 && src[x])
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = '\0';
	}
	x = 0;
	while (src[x])
		x++;
	return (x);
}

/*int main()
{
	char src[] = "oki";
	char dst[] = "aaa";
	printf("%s\n", dst);
	printf("%zu\n", ft_strlcpy(dst, src, 5));
	printf("%s", dst);
}*/
